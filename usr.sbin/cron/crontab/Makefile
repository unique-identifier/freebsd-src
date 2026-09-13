BINDIR=	/usr/bin

PACKAGE=cron
PROG=	crontab
BINOWN=	root
BINMODE=4555
PRECIOUSPROG=

WARNS?=	3

CFLAGS+= -I${.CURDIR:H}/cron

LIBADD=	cron md util

.include <bsd.prog.mk>
