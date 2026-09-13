SHLIBDIR?=	/lib

.include <src.opts.mk>

SHLIB_MAJOR=	2
INCSDIR?=	${INCLUDEDIR}/casper

.if ${MK_CASPER} != "no"
SHLIB=	cap_dns

SRCS=	cap_dns.c
.endif

INCS=	cap_dns.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
