PACKAGE=	iscsi
PROG=		iscsictl
SRCS=		iscsictl.c periphs.c parse.y token.l y.tab.h
CFLAGS+=	-I${.CURDIR}
CFLAGS+=	-I${SRCTOP}/sys/dev/iscsi
CFLAGS+=	-I${SRCTOP}/lib/libiscsiutil

LIBADD=		iscsiutil util xo

YFLAGS+=	-v
LFLAGS+=	-i
CLEANFILES=	y.tab.c y.tab.h y.output

NO_WMISSING_VARIABLE_DECLARATIONS=

.include <bsd.prog.mk>
