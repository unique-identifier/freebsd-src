SHLIBDIR?=	/lib

.include <src.opts.mk>

.if ${MK_CASPER} != "no"
SHLIB=	casper
SHLIB_MAJOR=	1

SRCS=	libcasper.c
SRCS+=	libcasper_impl.c
SRCS+=	libcasper_service.c
SRCS+=	service.c
SRCS+=	zygote.c
.endif

INCS=	libcasper.h
INCS+=	libcasper_service.h

LIBADD=	nv

CFLAGS+=-I${.CURDIR}

.include <bsd.lib.mk>
