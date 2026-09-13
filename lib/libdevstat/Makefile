LIB=	devstat
SHLIBDIR?= /lib
# Bump DEVSTAT_USER_API_VER in devstat.h every time this is incremented.
SHLIB_MAJOR= 7
SRCS=	devstat.c
INCS=	devstat.h

LIBADD=	kvm

CFLAGS+=-I${.CURDIR}

WARNS?=	3

.include <bsd.lib.mk>
