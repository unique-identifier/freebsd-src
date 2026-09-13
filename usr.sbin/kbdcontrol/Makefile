PACKAGE=	console-tools
PROG=	kbdcontrol
SRCS=	kbdcontrol.c lex.l

WARNS?=	4
CFLAGS+= -I${.CURDIR}

.ifdef BOOTSTRAPPING
# Provide minimal load and dump functionality
CFLAGS+= -DBOOTSTRAP_KBDCONTROL
.else
# temporarily added for pre-Unicode accent key API/ABI compatibility
CFLAGS+= -DCOMPAT_FREEBSD13
.endif

.include <bsd.prog.mk>
