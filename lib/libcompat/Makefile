PACKAGE=lib${LIB}
LIB=	compat
CFLAGS+=-I${SRCTOP}/lib/libc/locale
NO_PIC=

WARNS?=	0

.PATH:	${.CURDIR}/4.3 ${.CURDIR}/4.4

# compat 4.3 sources
SRCS+=	re_comp.c rexec.c

# compat 4.4 sources
SRCS+=	cuserid.c

.include <bsd.lib.mk>
