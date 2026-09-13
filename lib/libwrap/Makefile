.include <src.opts.mk>

PACKAGE=	tcpd

CONFS=	hosts.allow
LIB=	wrap
SHLIB_MAJOR= 6
INCS=	tcpd.h

.PATH:	${SRCTOP}/contrib/tcp_wrappers

CFLAGS+=-DFACILITY=LOG_AUTH -DHOSTS_ACCESS -DNETGROUP -DDAEMON_UMASK=022 \
	-DREAL_DAEMON_DIR=\"${LIBEXECDIR}\" -DPROCESS_OPTIONS \
	-DSEVERITY=LOG_INFO -DRFC931_TIMEOUT=10 \
	-DHOSTS_DENY=\"/etc/hosts.deny\" -DHOSTS_ALLOW=\"/etc/hosts.allow\" \
	-DSYS_ERRLIST_DEFINED -DALWAYS_HOSTNAME -DUSE_STRSEP -DPROCESS_OPTIONS
.if ${MK_NIS} == "no"
CFLAGS+= -DUSE_GETDOMAIN
.endif
.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+=-DINET6
.endif

WARNS?=	0

SRCS=	clean_exit.c diag.c eval.c fix_options.c fromhost.c \
	hosts_access.c hosts_ctl.c misc.c myvsyslog.c options.c \
	percent_m.c percent_x.c refuse.c rfc931.c shell_cmd.c \
	socket.c tli.c update.c workarounds.c libvars.c

.include <bsd.lib.mk>
