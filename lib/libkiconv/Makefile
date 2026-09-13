SHLIBDIR?=	/lib

.include <src.opts.mk>

PACKAGE=	runtime
LIB=		kiconv
SRCS=		kiconv_sysctl.c xlat16_iconv.c xlat16_sysctl.c
SRCS+=		quirks.c

SHLIB_MAJOR=	4

CFLAGS+=	-I${SRCTOP}/sys

WARNS?=		1

.if ${MK_ICONV} == "no"
CFLAGS+=	-DICONV_DLOPEN
.endif

.include <bsd.lib.mk>
