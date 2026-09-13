PACKAGE=runtime
PROG=	umount
SRCS=	umount.c vfslist.c mounttab.c

MOUNT=	${.CURDIR:H}/mount
UMNTALL= ${SRCTOP}/usr.sbin/rpc.umntall
CFLAGS+= -I${MOUNT} -I${UMNTALL}

.PATH: ${MOUNT} ${UMNTALL}

.include <bsd.prog.mk>
