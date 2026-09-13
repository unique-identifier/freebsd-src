.include <src.opts.mk>

PACKAGE=	newsyslog

CONFS=	newsyslog.conf
PROG=	newsyslog
SRCS=	newsyslog.c ptimes.c
LIBADD=	sbuf util

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests
SUBDIR+=	newsyslog.conf.d

.include <bsd.prog.mk>
