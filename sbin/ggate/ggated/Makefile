.PATH: ${.CURDIR:H}/shared

PROG=	ggated
SRCS=	ggated.c ggate.c
PACKAGE=	ggate

LIBADD=	pthread util

CFLAGS+= -I${.CURDIR:H}/shared

.include <bsd.prog.mk>
