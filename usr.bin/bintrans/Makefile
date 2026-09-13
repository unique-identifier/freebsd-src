.include <src.opts.mk>

PROG=	bintrans
SRCS=	bintrans.c uuencode.c uudecode.c qp.c
LINKS+=	${BINDIR}/bintrans ${BINDIR}/uuencode
LINKS+=	${BINDIR}/bintrans ${BINDIR}/b64encode
LINKS+=	${BINDIR}/bintrans ${BINDIR}/uudecode
LINKS+=	${BINDIR}/bintrans ${BINDIR}/b64decode
LINKS+=	${BINDIR}/bintrans ${BINDIR}/base64

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
