PACKAGE=at
MAINSRC=${SRCTOP}/usr.bin/at

.include "${MAINSRC}/Makefile.inc"

PROG=	atrun
SRCS=	atrun.c gloadavg.c

BINDIR=	${ATLIB_DIR}

CFLAGS+=-I${MAINSRC} -I${.CURDIR}
CFLAGS+=-DLOGIN_CAP -DPAM

WARNS?=	2
WFORMAT=0

LIBADD=	pam util

.include <bsd.prog.mk>
