.include <src.opts.mk>

PACKAGE=runtime
PROG=	newfs_msdos
SRCS=	newfs_msdos.c mkfs_msdos.c

# XXX - this is verboten
.if ${MACHINE_CPUARCH} == "arm"
WARNS?= 3
.endif

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
