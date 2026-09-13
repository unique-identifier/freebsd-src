PACKAGE=nfs
PROG=	mount_nfs
SRCS=	mount_nfs.c mounttab.c
LIBADD=	util

UMNTALL= ${SRCTOP}/usr.sbin/rpc.umntall
CFLAGS+= -DNFS -I${UMNTALL}

.PATH: ${UMNTALL}

.include <bsd.prog.mk>
