# InfiniBand and RDMA removal

HalfBSD intends to remove the in-tree OpenFabrics (OFED), InfiniBand, and
RDMA stack in stages.  This file is the handoff and execution checklist.  Read
it before deleting anything: the `WITHOUT_OFED` boundary is incomplete, and
several Ethernet drivers share code or headers with their RDMA providers.

The intended scope is the in-tree RDMA implementation, its kernel consumers,
provider drivers, userland ABI, administration tools, and build integration.
Preserve ordinary Ethernet support for mlx4/mlx5, bnxt, qlnx, cxgbe, and ice.
Do not remove LinuxKPI, iSCSI over TCP, general packet capture, or lagg without
an explicit, independently justified change.

## Current state and important traps

- `OFED` is in the default-yes lists in `share/mk/src.opts.mk` and
  `sys/conf/kern.opts.mk`; it is only marked broken on 32-bit ARM.
- `OFED_EXTRA` defaults off and is forced off by `WITHOUT_OFED`.  It selects
  OpenSM and most InfiniBand diagnostic programs.
- Userland is rooted at `lib/ofed`, `usr.bin/ofed`, and `contrib/ofed`.  It
  installs libraries plus public `infiniband/` and `rdma/` headers.
- Kernel core and IPoIB/SDP live under `sys/ofed`; other consumers and providers
  live in `sys/dev`, `sys/contrib/rdma`, and `sys/modules`.
- The principal providers are mlx4ib, mlx5ib, mthca, irdma, iw_cxgbe, bnxt_re,
  and qlnxr.  iSER is an RDMA upper layer and krping is a test module.
- `sys/modules/bnxt/Makefile` and `sys/modules/qlnx/Makefile` select `bnxt_re`
  and `qlnxr` without the same `MK_OFED` gate used by the top-level module
  list.  Treat this as a boundary bug during the default-off stage.
- mlx4 and mlx5 core sources include RDMA headers.  The ice module builds RDMA
  interface glue, and qlnxe has RDMA support files.  Untangle these before
  deleting `sys/ofed/include` so their Ethernet drivers continue to build.
- `sys/conf/files` selects `net/if_infiniband.c` for `ofed | lagg`.  Decide
  explicitly whether `laggtype infiniband` is removed; it is not safe to infer
  that merely deleting OFED makes this file unused.
- `libpcap` conditionally builds `pcap-rdmasniff.c` and gains dependencies on
  ibverbs, mlx5, and bnxtre.  Preserve all non-RDMA capture functionality.
- `tools/build/mk/OptionalObsoleteFiles.inc` is the best installed-file
  inventory, but check it against actual install manifests.  On final removal,
  move entries to the tree's permanent obsolete-file mechanism rather than
  deleting the cleanup list with the option.

## Step 1 — Freeze the boundary and announce removal

- [ ] Inventory the stack by category: kernel core/KPI, upper layers, provider
      drivers, userland ABI, utilities, startup integration, documentation,
      tests, packages, and installed files.
- [ ] Start from `share/mk/src.opts.mk`, `sys/conf/files`, `sys/conf/options`,
      `sys/conf/NOTES`, `sys/modules/Makefile`, `lib/ofed/Makefile`,
      `usr.bin/ofed/Makefile`, and `OptionalObsoleteFiles.inc`.
- [ ] Include `sys/ofed`, `sys/dev/{iser,mthca,irdma}`,
      `sys/dev/mlx4/mlx4_ib`, `sys/dev/mlx5/mlx5_ib`,
      `sys/dev/bnxt/bnxt_re`, `sys/dev/qlnx/qlnxr`,
      `sys/dev/cxgbe/iw_cxgbe`, and `sys/contrib/rdma` in the audit.
- [ ] Decide whether the public user ABI and kernel KPI get a temporary
      compatibility window for ports or out-of-tree modules.  Record the
      answer here before changing headers.
- [ ] Add an `UPDATING`/release-note deprecation notice with target release
      milestones and the temporary `WITH_OFED=yes` escape hatch.

## Step 2 — Make OFED opt-in for one transition cycle

- [ ] Move `OFED` from default-yes to default-no in both source and kernel
      option machinery.  Retain `WITH_OFED` temporarily and continue forcing
      `OFED_EXTRA` off whenever OFED is off.
- [ ] Update the source input for `src.conf(5)` (not only generated output) to
      describe the new default and deprecation period.
- [ ] Gate every RDMA module consistently when `MK_OFED=no`, especially
      `bnxt_re`, `qlnxr`, `iw_cxgbe`, irdma, mlx4ib, mlx5ib, mthca, ibcore,
      ipoib, iser, and `rdma/krping`.
- [ ] Make ice RDMA glue conditional where possible.  Audit the corresponding
      entries in `sys/conf/files.amd64`, `files.arm64`, and `files.powerpc`.
- [ ] Build-test the default-off configuration before removing sources.  Fix
      leaked RDMA header/library dependencies instead of papering over them.
- [ ] Install over an OFED-enabled image and verify that the existing optional
      obsolete list removes all now-disabled binaries, libraries, links,
      headers, rc scripts, and configuration files.

## Step 3 — Remove OFED_EXTRA and OpenSM

- [ ] Remove the `OFED_EXTRA` option, its dependency rule, and its build-option
      documentation.
- [ ] Remove OpenSM, the extra InfiniBand diagnostic programs, their rc script,
      `opensm_enable` default, newsyslog fragment, mtree entries, and tests.
- [ ] Remove the corresponding imported sources in `contrib/ofed/opensm` and
      `contrib/ofed/infiniband-diags` once no retained target refers to them.
- [ ] Remove OpenSM support libraries and headers (`opensm`, `osmcomp`, and
      `osmvendor`).  Also remove ibmad, ibumad, and ibnetdisc at this point if
      the deliberately retained transition programs no longer need them.
- [ ] Convert removed `MK_OFED_EXTRA` installed-file cleanup to unconditional
      obsolete entries, deduplicating files listed under both OFED conditions.

## Step 4 — Remove upper layers and provider drivers

- [ ] Remove IPoIB and SDP sources, modules, kernel options (`IPOIB*`, `SDP*`),
      configuration entries, manuals, and netstat SDP presentation code.
- [ ] Remove iSER sources/module/configuration and its manual.  Update retained
      iSCSI documentation while preserving normal iSCSI over TCP.
- [ ] Remove `sys/contrib/rdma/krping` and `sys/modules/rdma`.
- [ ] Remove mthca, mlx4ib, mlx5ib, irdma, iw_cxgbe, bnxt_re, and qlnxr source,
      module directories, kernel configuration entries, architecture NOTES,
      manuals, and stale cross-references.
- [ ] Preserve mlx4/mlx4en, mlx5/mlx5en, cxgbe, bnxt_en, qlnxe, and ice.  Remove
      only their RDMA registration hooks, callbacks, tunables, generated
      interfaces, flags, and header dependencies.
- [ ] For ice, review `ice_rdma.c`, `irdma_if.m`, and `irdma_di_if.m`.  For
      qlnxe, review `ecore_rdma.c`, `qlnx_rdma.c`, and `files.amd64`.  For mlx4
      and mlx5, eliminate RDMA includes from core code without harming Ethernet
      queue, firmware, flow-steering, or management paths.
- [ ] Decide the `laggtype infiniband` question.  If removing it, update lagg
      code and documentation and then remove the `ofed | lagg` selection of
      `net/if_infiniband.c`.  Preserve other lagg modes.

## Step 5 — Remove userland libraries, headers, and utilities

- [ ] Remove the remaining `lib/ofed`, `usr.bin/ofed`, and unused
      `contrib/ofed` contents, including ibverbs, rdmacm, provider libraries,
      ibstat, and verbs/rdmacm examples.
- [ ] Remove their top-level `SUBDIR.${MK_OFED}` entries and OFED prebuild
      library handling in `Makefile.inc1`.
- [ ] Remove OFED library declarations, dependency graphs, and object paths
      from `share/mk/src.libnames.mk`, `share/mk/bsd.libnames.mk`, generated
      `Makefile.depend` files, and `tools/make_libdeps.sh`.
- [ ] Remove installed `/usr/include/infiniband` and `/usr/include/rdma`
      declarations and their mtree directories.
- [ ] Remove libpcap's RDMA capture source and OFED library dependencies,
      including `lib/libpcap/Makefile.depend.options` and the bsdbox hostapd
      workaround.  Verify ordinary libpcap ABI and capture backends remain.
- [ ] Remove remaining package metadata such as `FreeBSD-rdma` references.
- [ ] Reconcile actual install output with obsolete-file records, including
      libraries installed under both `/lib` and `/usr/lib`.

## Step 6 — Delete the kernel core and retire OFED options

- [ ] Confirm no retained source includes `<rdma/...>` or depends on symbols
      exported by ibcore.
- [ ] Delete `sys/ofed` and `sys/modules/ibcore`.
- [ ] Remove `OFED` and `OFED_DEBUG_INIT` from kernel option files, NOTES, and
      source manifests.  Remove all residual `opt_ofed.h` references.
- [ ] Delete `OFED` from source and kernel option machinery and remove the
      `WITH_OFED`/`WITHOUT_OFED` documentation.
- [ ] Remove every remaining `MK_OFED` conditional from build, manual,
      bootstrap, dependency, and cleanup integration.
- [ ] Add a final `UPDATING` entry covering removed device modules, kernel KPI,
      device nodes, public headers, libraries, and obsolete local src.conf or
      kernel-config settings.  Point users to an external replacement only if
      one has actually been selected and tested.

## Step 7 — Validate the completed removal

- [ ] Categorize every remaining case-insensitive OFED/InfiniBand/RDMA match as
      intentional protocol data, imported portable code, hardware naming,
      documentation/history, cleanup metadata, or a bug.  Do not delete by
      substring.
- [ ] Check deleted-header consumers, module and library source lists,
      dependency graphs, make conditional nesting, shell syntax, mtree syntax,
      stale manual cross-references, and `git diff --check`.
- [ ] Build world and GENERIC kernels for amd64 and arm64 with normal HalfBSD
      settings.  Build all retained modules to catch parent-directory leaks.
- [ ] Install over an image that previously contained OFED and verify all
      removed installed artifacts are cleaned while unrelated configuration
      and user data remain.
- [ ] Boot-test Ethernet on available mlx4/mlx5, bnxt, qlnx, cxgbe, and ice
      hardware or arrange equivalent project testing.  Test iSCSI/TCP, lagg,
      libpcap, and normal network startup.
- [ ] Record commands, results, deliberate leftovers, and any external
      migration path in this file before marking removal complete.

## Useful starting searches

Inspect and classify matches; do not feed these directly to a deletion loop.

```sh
git grep -n -E 'MK_OFED|WITH_OFED|WITHOUT_OFED|OFED_EXTRA|opt_ofed'
git grep -n -i -E '\b(ofed|infiniband|rdma|ibcore|ipoib|iser|krping)\b'
git grep -n -E '<(rdma|infiniband)/|sys/ofed|contrib/ofed'
git grep -n -E 'mlx[45]ib|mthca|irdma|iw_cxgbe|bnxt_re|qlnxr'
git grep -n -E 'opensm|ibverbs|rdmacm|ibumad|ibmad|ibnetdisc'
```

Useful build/install manifests to revisit at every stage:

```text
Makefile.inc1
share/mk/src.opts.mk
share/mk/src.libnames.mk
share/mk/bsd.libnames.mk
sys/conf/{files,options,NOTES,kern.opts.mk}
sys/modules/Makefile
lib/Makefile
usr.bin/Makefile
tools/build/mk/OptionalObsoleteFiles.inc
etc/mtree/BSD.include.dist
```
