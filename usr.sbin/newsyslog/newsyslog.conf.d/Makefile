.include <src.opts.mk>

PACKAGE=	newsyslog
CONFSDIR=	/etc/newsyslog.conf.d

CONFGROUPS=	CONFS
CONFS=

.if ${MK_OFED} != "no"
CONFS+=		opensm.conf
.endif

.include <bsd.prog.mk>
