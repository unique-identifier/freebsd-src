# PPP and SLIP removal

HalfBSD is removing legacy PPP/SLIP networking in stages. This file records
where to resume after the userland removal. Do not treat phase 1 as removal
of kernel PPP support.

## Step 1 — Userland removal completed

Removed `ppp`, `pppctl`, `pppoed`, and Bluetooth `rfcomm_pppd`, their source,
startup scripts, configuration, logging rules, examples, package dependencies,
and the `PPP` source option. Removed userland build-option documentation.
Updated startup ordering to preserve dependencies on `netif` without the
removed `ppp` service. Added unconditional installed-file cleanup and an
UPDATING entry. Other Bluetooth services remain.

Shell syntax, whitespace, makefile nesting, mtree structure, and build-reference
checks are performed locally on Linux. FreeBSD build and runtime validation
is still pending. No kernel sources or shared libraries are removed in step 1.

## Step 2 — Remove the kernel PPP family

- [x] Remove Netgraph PPP, PPPoE, PPTP GRE, L2TP, asynchronous PPP framing,
      and PPP compression/encryption nodes: `ppp`, `pppoe`, `pptpgre`, `l2tp`,
      `async`, `vjc`, `deflate`, `pred1`, and `mppc`.
- [x] Remove their sources, exported headers, module directories, kernel
      options, NOTES entries, documentation, and examples.
- [x] Update `sys/conf/files`, `sys/conf/options`, `sys/modules/netgraph`,
      and `lib/libnetgraph/debug.c` registrations/includes together.
- [x] Audit consumers before removing `sys/net/ppp_defs.h` or other headers.
      `ppp_defs.h` remains for compiler-rt ABI checks. RADIUS now keeps its
      MPPE key-size limit locally instead of including the removed `ng_mppc.h`.

## Step 3 — Finish the SLIP and dial-up audit

- [x] Confirm absence of standalone SLIP, `slattach`, and `sppp` implementations
      beyond the initial filename inventory. Remove obsolete remnants,
      including the surviving `NETGRAPH_SPPP` option where unused.
- [x] Remove `sys/net/slcompress.c` with `ng_vjc`; resolve header consumers first.
      The wire-format header remains temporarily for the tcpdump audit in step 4.
- [x] Examine standalone `usr.bin/chat` and serial-network examples for removal.
      Preserve serial consoles, getty, and general terminal utilities.
- [x] Treat Frame Relay and Cisco HDLC as an explicit scope decision before
      deleting those independent protocols.

The audit found no standalone SLIP, slattach, or sppp implementation.  It
removed the orphaned `NETGRAPH_SPPP` option, VJ compression implementation,
standalone dial-up `chat` program, and obsolete bsdconfig serial-network text.
The `stty` SLIP line-discipline name is retained as a terminal ABI name, while
portable capture/file-identification definitions remain for decoding existing
traffic and files.  Netgraph Frame Relay (RFC 1490/2427) and Cisco HDLC are
independent link protocols and remain in scope as supported Netgraph nodes.

## Step 4 — Untangle shared dependencies

- [x] Decouple `lib/libradius/radlib.c` from `netgraph/ng_mppc.h`; it used
      `MPPE_KEY_LEN`. RADIUS functionality and public APIs remain intact.
- [x] Audit `contrib/tcpdump/print-ppp.c` and other capture consumers before
      deleting `net/slcompress.h`. Preserve capture decoding using appropriate
      wire-format definitions; do not remove unrelated libpcap functionality.
- [x] Audit `PAM_SUPPORT`: PPP was its only direct MK_PAM_SUPPORT consumer in
      the initial search, but `share/mk/local.dirdeps-options.mk` also refers
      to it. Resolve the option machinery separately; preserve PAM itself.
- [x] Preserve TUN/TAP, general Netgraph infrastructure, IPFW, NAT, general
      tunneling, Bluetooth outside PPP, and shared crypto/compression libraries.
- [x] Preserve assigned protocol numbers and ABI constants where appropriate;
      document why remaining PPP/SLIP names are needed.

Tcpdump now uses its own portable RFC 1144 wire-format definitions for PPP and
SLIP capture decoding, so the kernel implementation header is removed without
reducing libpcap or tcpdump file-format support.  The unused `PAM_SUPPORT`
application option and its stale dirdeps mapping are removed; the independent
`PAM` option, library, and modules remain.  TUN/TAP, IPFW/NAT, Bluetooth,
general tunneling and Netgraph, and shared crypto/compression code are outside
the removed protocol implementation and remain unchanged.  Remaining PPP/SLIP
names identify assigned wire protocols and ethertypes, pcap DLT values and
decoders, compatibility ABI values, historical text, or upgrade cleanup—not
live PPP/SLIP interfaces.

## Step 5 — Finish integration and upgrade cleanup

- [x] Audit remaining startup, install, package, dependency, test, and example
      integration for kernel/protocol components being removed.
- [x] Recheck networking/IPFW startup ordering. Step 1 already removed `ppp`
      from NETWORKING, routing, bridge, and netstart, and changed IPFW's
      prerequisite to `netif` (the old PPP service prerequisite).
- [x] Remove stale userland PPP references in retained device/protocol manuals,
      including `bridge.4`, `tun.4`, `u3g.4`, `ucom.4`, and Netgraph manuals.
- [x] Add unconditional obsolete entries for removed modules and headers;
      move applicable entries from OptionalObsoleteFiles.inc rather than
      retaining obsolete option checks. Existing ObsoleteManFiles.inc covers
      old installed system manuals.
- [x] Extend UPDATING with kernel configuration migration instructions.
      Preserve local profiles/logs; do not recursively delete user data.

The integration audit found no remaining startup-order dependency on PPP;
IPFW and the NETWORKING milestone continue to depend on `netif`.  Obsolete
kernel modules and exported headers are now removed unconditionally, and the
upgrade notes list every deleted kernel option and call out local loader
configuration.  Retained device and Netgraph manuals no longer direct users to
removed PPP programs or nodes.  Getty's PPP-specific auto-login path was also
removed while ordinary serial login support remains intact.  Local profiles
and logs continue to be preserved.

## Step 6 — Validate the complete removal

- [ ] Repeat source-option and protocol searches, categorizing all remaining
      references as active functionality, wire/ABI definitions, portable
      imported code, documentation/history, or installed-file cleanup.
- [ ] Check deleted-header consumers, module source lists, dependency graphs,
      makefile conditional nesting, edited shell syntax, mtree structure,
      and `git diff --check`.
- [ ] On the dedicated FreeBSD amd64 development host, complete `buildworld`
      and `buildkernel` with the existing HalfBSD src.conf.
- [ ] Boot the resulting system and validate networking startup, IPFW,
      TUN/TAP users, relevant Netgraph consumers, and packet capture.
- [ ] Record validation results and remaining intentional references here
      before marking the overall removal complete.

Useful starting searches (inspect matches rather than deleting by substring):

```sh
git grep -n -E 'MK_PPP|WITHOUT_PPP|WITH_PPP|PPP_NO_'
git grep -n -i -E '\b(ppp|slip|sppp|pppoe|pppoed|slattach|pppctl|rfcomm_pppd)\b'
git grep -n -E 'ng_(async|deflate|l2tp|mppc|ppp|pppoe|pptpgre|pred1|vjc)|slcompress|ppp_defs'
```
