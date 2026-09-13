# $Id: Makefile,v 1.5 2003/07/22 18:38:04 max Exp $

PACKAGE=	bluetooth
LIB_PACKAGE=

CONFS=		hosts protocols
CONFSDIR=	/etc/bluetooth
CONFSMODE_protocols=	444
LIB=		bluetooth

WARNS?=		2
CFLAGS+=	-I${.CURDIR} -I${SRCTOP}/sys

SHLIB_MAJOR=	4

SRCS=		bluetooth.c dev.c hci.c
INCS=		bluetooth.h

.include <bsd.lib.mk>
