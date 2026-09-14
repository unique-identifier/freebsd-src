.include <src.opts.mk>

PACKAGE=	newsyslog
CONFSDIR=	/etc/newsyslog.conf.d

CONFGROUPS=	CONFS
CONFS=

.if ${MK_OFED} != "no"
CONFS+=		opensm.conf
.endif

.if ${MK_PPP} != "no"
CONFGROUPS+=	PPP
PPP+=		ppp.conf
PPPPACKAGE=	ppp
PPPDIR=		/etc/newsyslog.conf.d
.endif

.include <bsd.prog.mk>
