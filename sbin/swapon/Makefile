PACKAGE=runtime
PROG=	swapon
LINKS=	${BINDIR}/swapon ${BINDIR}/swapoff
LINKS+=	${BINDIR}/swapon ${BINDIR}/swapctl

LIBADD=	util

.include <src.opts.mk>

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
