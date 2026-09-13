.include <src.opts.mk>

CONFS=	inetd.conf
PROG=	inetd
PACKAGE=	inetd
SRCS=	inetd.c builtins.c

CFLAGS+= -DLOGIN_CAP
#CFLAGS+= -DSANITY_CHECK

.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+= -DINET6
.endif

LIBADD=	util

.if ${MK_TCP_WRAPPERS} != "no"
CFLAGS+=	-DLIBWRAP
LIBADD+=	wrap
.endif

CFLAGS+= -DIPSEC
LIBADD+=	ipsec

.include <bsd.prog.mk>
