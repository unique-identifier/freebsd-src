PACKAGE=	dpv
LIB=		dpv
SHLIB_MAJOR=	3
INCS=		dpv.h

LIBADD=	dialog figpar util tinfow ncursesw

SRCS=		dialog_util.c dialogrc.c dprompt.c dpv.c status.c util.c

CFLAGS+=	-I${.CURDIR}

.include <bsd.lib.mk>
