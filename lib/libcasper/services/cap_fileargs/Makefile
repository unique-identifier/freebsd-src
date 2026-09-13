SHLIBDIR?=	/lib

.include <src.opts.mk>

SHLIB_MAJOR=	1
INCSDIR?=	${INCLUDEDIR}/casper

.if ${MK_CASPER} != "no"
SHLIB=	cap_fileargs

SRCS=	cap_fileargs.c
.endif

INCS=	cap_fileargs.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
