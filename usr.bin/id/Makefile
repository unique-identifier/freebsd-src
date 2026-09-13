.include <src.opts.mk>

PACKAGE=	runtime

PROG=	id
LINKS=	${BINDIR}/id ${BINDIR}/groups
LINKS+=	${BINDIR}/id ${BINDIR}/whoami

.if ${MK_AUDIT} != "no"
CFLAGS+=	-DUSE_BSM_AUDIT
.endif

.include <bsd.prog.mk>
