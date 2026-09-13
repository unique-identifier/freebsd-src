PACKAGE=	efi-tools

PROG=	efivar

LIBADD= efivar geom

SRCS=	efivar.c efiutil.c

EFIBOOT=${SRCTOP}/stand/efi
CFLAGS+=	-I${EFIBOOT}/include

.include <bsd.prog.mk>
