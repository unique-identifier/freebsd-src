SHLIBDIR?=	/lib

.include <src.opts.mk>

SHLIB_MAJOR=	1
INCSDIR?=	${INCLUDEDIR}/casper

.if ${MK_CASPER} != "no"
SHLIB=	cap_syslog

SRCS=	cap_syslog.c
.endif

INCS=	cap_syslog.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}

.include <bsd.lib.mk>
