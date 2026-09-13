SHLIBDIR?=	/lib

.include <src.opts.mk>

SHLIB_MAJOR=	1
INCSDIR?=	${INCLUDEDIR}/casper

.if ${MK_CASPER} != "no"
SHLIB=	cap_grp

SRCS=	cap_grp.c
.endif

INCS=	cap_grp.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>

# GCC 13 complains incorrectly about free after failed realloc: GCC bug #110501
CFLAGS.cap_grp.c+= ${NO_WUSE_AFTER_FREE}
