PACKAGE=runtime
LIB=	stdthreads
SHLIB_MAJOR= 0

INCS=	threads.h
SRCS=	threads.h call_once.c cnd.c mtx.c thrd.c tss.c

LIBADD=	pthread

VERSION_DEF= ${SRCTOP}/lib/libc/Versions.def
SYMBOL_MAPS= ${.CURDIR}/Symbol.map

.include <bsd.lib.mk>
