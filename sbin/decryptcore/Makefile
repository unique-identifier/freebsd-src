PROG=	decryptcore

CFLAGS+=-DOPENSSL_API_COMPAT=0x10100000L
LIBADD=	crypto pjdlog

CFLAGS+=-I${SRCTOP}/lib/libpjdlog

.include <bsd.prog.mk>
