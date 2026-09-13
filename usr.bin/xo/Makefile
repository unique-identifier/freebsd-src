.include <src.opts.mk>

LIBXOSRC=	${SRCTOP}/contrib/libxo

.PATH:	${LIBXOSRC}/xo

PROG=	xo

# XXX For xoversion.h
CFLAGS+=-I${LIBXOSRC}/libxo

# XXX For xo_config.h
CFLAGS+=-I${SRCTOP}/lib/libxo/libxo

LIBADD=	xo util

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>

CWARNFLAGS+=	${NO_WUNUSED_BUT_SET_VARIABLE}
