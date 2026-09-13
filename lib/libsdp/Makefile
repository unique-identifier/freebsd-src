# $Id: Makefile,v 1.2 2003/09/07 20:34:19 max Exp $

PACKAGE=	bluetooth
LIB_PACKAGE=
LIB=		sdp

WARNS?=		2
CFLAGS+=	-I${.CURDIR}

SHLIB_MAJOR=	4

SRCS=		search.c service.c session.c util.c
INCS=		sdp.h

.include <bsd.lib.mk>
