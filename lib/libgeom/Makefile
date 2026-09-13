PACKAGE=	runtime

LIB=	geom
SHLIBDIR?= /lib
SRCS+=	geom_getxml.c
SRCS+=	geom_stats.c
SRCS+=	geom_xml2tree.c
SRCS+=	geom_ctl.c
SRCS+=	geom_util.c
INCS=	libgeom.h

CFLAGS += -I${.CURDIR}

WARNS?=	3

LIBADD+=	bsdxml sbuf

.include <bsd.lib.mk>
