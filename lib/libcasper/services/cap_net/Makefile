SHLIBDIR?=	/lib

.include <src.opts.mk>

SHLIB_MAJOR=	1
INCSDIR?=	${INCLUDEDIR}/casper

.if ${MK_CASPER} != "no"
SHLIB=	cap_net

SRCS=	cap_net.c
.endif

INCS=	cap_net.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}
CFLAGS+=-DWITH_CASPER

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
