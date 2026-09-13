.PATH:	${SRCTOP}/contrib/pf/ftp-proxy

PACKAGE=	pf
PROG=	ftp-proxy

SRCS=	ftp-proxy.c filter.c

CFLAGS+=-I${SRCTOP}/contrib/pf/libevent
CFLAGS+= -I${SRCTOP}/lib/libpfctl -I${OBJTOP}/lib/libpfctl

LIBADD=	event1 pfctl

WARNS?=	3

.include <bsd.prog.mk>
