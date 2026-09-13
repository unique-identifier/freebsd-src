.include <src.opts.mk>

NO_OBJ=

CONFGROUPS=	CONFS
CONFS=	README \
	imap \
	login \
	other \
	passwd pop3 \
	sshd su system \
	xdm

CONFDIR=	/etc/pam.d
CONFSMODE_README=	444

CONFGROUPS+=	CRON
CRON=		cron
CRONPACKAGE=	cron

CONFGROUPS.${MK_AT}+=	AT
AT=		atrun
ATPACKAGE=	at

# FTP servers from ports use these PAM configurations.
CONFGROUPS+=	FTP
FTP=		ftp ftpd
FTPPACKAGE=	pam

.include <bsd.prog.mk>
