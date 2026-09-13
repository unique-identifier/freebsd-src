# Author: Shteryana Shopova <syrinx@FreeBSD.org>

.include <src.opts.mk>

.PATH: ${.CURDIR}

PROG=	bsnmpget

LIBADD=	bsnmp bsnmptools

CFLAGS+=	-I${.CURDIR:H}/libbsnmptools
LDFLAGS+=	-L${.OBJDIR:H}/libbsnmptools

LINKS=  ${BINDIR}/bsnmpget ${BINDIR}/bsnmpwalk
LINKS+=  ${BINDIR}/bsnmpget ${BINDIR}/bsnmpset

.include <bsd.prog.mk>
