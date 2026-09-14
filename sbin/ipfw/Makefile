.include <src.opts.mk>

PACKAGE=ipfw
PROG=	ipfw

LINKS=	${BINDIR}/ipfw ${BINDIR}/dnctl

SRCS=	ipfw2.c dummynet.c ipv6.c main.c nat.c tables.c
SRCS+=	nat64clat.c nat64lsn.c nat64stl.c nptv6.c

LIBADD=	jail util

HAS_TESTS=
SUBDIR.${MK_TESTS}=     tests

.include <bsd.prog.mk>

CWARNFLAGS+= -Wno-cast-align
