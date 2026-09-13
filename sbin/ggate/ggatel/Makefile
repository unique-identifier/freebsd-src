.PATH: ${.CURDIR:H}/shared

PROG=	ggatel
SRCS=	ggatel.c ggate.c
PACKAGE=	ggate

CFLAGS+= -DLIBGEOM
CFLAGS+= -I${.CURDIR:H}/shared

LIBADD=	geom util

.include <bsd.prog.mk>
