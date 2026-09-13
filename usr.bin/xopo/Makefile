.include <src.opts.mk>

LIBXOSRC=	${SRCTOP}/contrib/libxo

.PATH:	${LIBXOSRC}/xopo

PROG=	xopo

# XXX For xoversion.h
CFLAGS+=-I${LIBXOSRC}/libxo

# XXX For xo_config.h
CFLAGS+=-I${SRCTOP}/lib/libxo

LIBADD=	xo util

.include <bsd.prog.mk>
