PACKAGE=	ipf
PROG=		ipscan
SRCS=		${GENHDRS} ipscan_y.c

GENHDRS+=	ipscan_y.h
CLEANFILES+=	${GENHDRS} ipscan_y.c

ipscan_y.c: ipscan_y.y
	${YACC} -d ${.ALLSRC}

ipscan_y.h: ipscan_y.c

.include <bsd.prog.mk>
