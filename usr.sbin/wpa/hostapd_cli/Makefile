.include "../Makefile.inc"

.include "../Makefile.crypto"

.PATH.c:${HOSTAPD_DISTDIR}

PACKAGE=	hostapd
PROG=	hostapd_cli
SRCS=	hostapd_cli.c

LIBADD+=	util wpacommon wpautils

.include <bsd.prog.mk>
