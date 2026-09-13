.include <src.opts.mk>

PACKAGE=	periodic

CONFS=	340.noid \
	450.status-security \
	999.local

# NB: keep these sorted by MK_* knobs

.if ${MK_LOCATE} != "no"
CONFS+=	310.locate
.endif

.include <bsd.prog.mk>
