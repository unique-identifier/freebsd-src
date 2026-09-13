.PATH:	${SRCTOP}/contrib/pf/authpf

PACKAGE=pf
PROG=	authpf
BINOWN=	root
BINGRP= authpf
BINMODE= 6555

SRCS=   authpf.c

# XXX ALTQ:
CFLAGS+= -DENABLE_ALTQ
CFLAGS+= -I${SRCTOP}/lib/libpfctl -I${OBJTOP}/lib/libpfctl

LIBADD=	m util pfctl

WARNS?=	3

LINKS=	${BINDIR}/authpf ${BINDIR}/authpf-noip

.include <bsd.prog.mk>
