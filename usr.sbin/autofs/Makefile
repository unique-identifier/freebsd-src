CONFS=	auto_master
PACKAGE=autofs
PROG=	automountd
SRCS=	automount.c
SRCS+=	automountd.c
SRCS+=	autounmountd.c
SRCS+=	common.c
SRCS+=	defined.c
SRCS+=	log.c
SRCS+=	popen.c
SRCS+=	token.l

CFLAGS+=-I${.CURDIR}
CFLAGS+=-I${SRCTOP}/sys/fs/autofs

LIBADD=	util

LINKS=	${BINDIR}/automountd ${BINDIR}/automount
LINKS+=	${BINDIR}/automountd ${BINDIR}/autounmountd

SUBDIR=	autofs

.include <bsd.prog.mk>
