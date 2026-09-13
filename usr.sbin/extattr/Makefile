PROG=	rmextattr

LIBADD=	sbuf

LINKS+=	${BINDIR}/rmextattr ${BINDIR}/getextattr
LINKS+=	${BINDIR}/rmextattr ${BINDIR}/setextattr
LINKS+=	${BINDIR}/rmextattr ${BINDIR}/lsextattr

.include <src.opts.mk>

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
