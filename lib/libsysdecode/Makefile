.include <src.opts.mk>

LIB=	sysdecode

SRCS=	errno.c flags.c ioctl.c signal.c syscallnames.c utrace.c support.c
.if ${MACHINE_CPUARCH} == "aarch64" || ${MACHINE_CPUARCH} == "amd64" || \
	${MACHINE_CPUARCH} == "i386"
SRCS+= linux.c
.endif
INCS=	sysdecode.h

CFLAGS+= -I${.OBJDIR}
CFLAGS+= -I${SRCTOP}/sys
CFLAGS+= -I${SRCTOP}/libexec/rtld-elf

CLEANFILES= ioctl.c ioctl.c.tmp tables.h tables_linux.h

# XXX: The flags should come from bsd.compat.mk / Makefile.libcompat
.if ${COMPAT_LIBCOMPAT:U} == "32"
CPP+=	-m32
.endif

.if ${MK_PF} != "no"
CFLAGS+=-DPF
.endif

# Workaround duplicate declarations in <netinet/ip_compat.h>
CFLAGS.gcc.ioctl.c+= -Wno-redundant-decls

CFLAGS.gcc+=	${CFLAGS.gcc.${.IMPSRC}}

DEPENDOBJS+=	tables.h tables_linux.h
.if ${MK_DIRDEPS_BUILD} == "yes"
MKTABLES_INCLUDEDIR= ${STAGE_INCLUDEDIR}
.else
MKTABLES_INCLUDEDIR= ${SYSROOT:U${DESTDIR}}${INCLUDEDIR}
.endif
tables.h: mktables
	sh ${.CURDIR}/mktables ${MKTABLES_INCLUDEDIR} ${.TARGET}
tables_linux.h: mklinuxtables
	sh ${.CURDIR}/mklinuxtables ${SRCTOP}/sys ${.TARGET}

# mkioctls runs find(1) for headers so needs to rebuild every time.  This used
# to be a hack only done in buildworld.
.if !defined(_SKIP_BUILD)
ioctl.c.tmp: .PHONY
.endif
ioctl.c.tmp: mkioctls .META
	env CPP="${CPP}" MK_PF="${MK_PF}" \
	    /bin/sh ${.CURDIR}/mkioctls ${MKTABLES_INCLUDEDIR} > ${.TARGET}

ioctl.c: ioctl.c.tmp
	if [ ! -e ${.TARGET} ] || ! cmp -s ${.TARGET} ${.TARGET}.tmp; then \
		mv -f ${.TARGET}.tmp ${.TARGET}; \
	fi

beforedepend: ioctl.c tables.h tables_linux.h

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
