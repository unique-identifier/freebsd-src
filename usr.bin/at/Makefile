.include "${.CURDIR}/Makefile.inc"

CONFS=	atrun
CONFSDIR=	/etc/cron.d
CONFSNAME=	at
PROG=	at
SRCS=	at.c panic.c parsetime.c perm.c
LINKS=	${BINDIR}/at ${BINDIR}/atq \
	${BINDIR}/at ${BINDIR}/atrm \
	${BINDIR}/at ${BINDIR}/batch

NO_WFORMAT=

BINOWN=	root
BINMODE= 4555

.include <bsd.prog.mk>
