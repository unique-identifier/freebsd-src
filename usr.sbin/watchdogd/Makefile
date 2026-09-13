PROG=	watchdogd
LINKS=	${BINDIR}/watchdogd ${BINDIR}/watchdog

LIBADD=	util

.include <bsd.prog.mk>

test:	${PROG}
	./${PROG} -t 1.0
