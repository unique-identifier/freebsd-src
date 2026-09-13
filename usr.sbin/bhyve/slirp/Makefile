.PATH: ${.CURDIR}/../

PROG= bhyve-slirp-helper
SRCS= slirp-helper.c config.c
CFLAGS+= -I${.CURDIR}/../
LIBADD= nv

BINDIR?= /usr/libexec

.include <bsd.prog.mk>
