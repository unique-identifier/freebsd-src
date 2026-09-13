.include <src.opts.mk>

.if ${MK_MAILWRAPPER} != "no"
PROG=	mailwrapper
MAN=	mailwrapper.8
LIBADD=	util
.endif

.if ${MK_MAILWRAPPER} != "no" || ${MK_DMAGENT} != "no"
SYMLINKS=	../sbin/mailwrapper /usr/bin/mailq \
		../sbin/mailwrapper /usr/bin/newaliases \
		mailwrapper /usr/sbin/sendmail
.if ${MK_MAILWRAPPER} == "no"
SYMLINKS+=	../libexec/dma ${BINDIR}/mailwrapper
.endif
.endif

.if ${MK_MAILWRAPPER} != "no"
SYMLINKS+=	..${BINDIR}/mailwrapper /bin/rmail
# Default to DMA; mailer.conf can select an alternative mail transport.
CONFS=		${SRCTOP}/libexec/dma/dmagent/mailer.conf
CONFSDIR=	/etc/mail
CONFSMODE=	644
.endif

.include <bsd.prog.mk>
