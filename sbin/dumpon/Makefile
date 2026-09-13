.include <src.opts.mk>

PACKAGE=runtime
PROG=	dumpon

.if ${MK_OPENSSL} != "no"
LIBADD=	crypto
CFLAGS+=-DHAVE_CRYPTO
CFLAGS+=-DOPENSSL_API_COMPAT=0x10100000L
.endif

.include <bsd.prog.mk>
