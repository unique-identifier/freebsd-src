PACKAGE=	iscsi
PROG=		iscsid
SRCS=		discovery.c iscsid.c login.c
CFLAGS+=	-I${.CURDIR}
CFLAGS+=	-I${SRCTOP}/sys/cam
CFLAGS+=	-I${SRCTOP}/sys/dev/iscsi
CFLAGS+=	-I${SRCTOP}/lib/libiscsiutil
CFLAGS+=	-DICL_KERNEL_PROXY

LIBADD=		iscsiutil util

.include <bsd.prog.mk>
