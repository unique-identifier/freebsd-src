SHLIBDIR?=      /lib

.include <src.opts.mk>

PACKAGE=	runtime

LIBXOSRC=	${SRCTOP}/contrib/libxo

.PATH:	${LIBXOSRC}/libxo

LIB=	xo
SHLIB_MAJOR=0

SRCS=	libxo.c xo_encoder.c xo_syslog.c

CFLAGS+=-I${LIBXOSRC}/libxo -I${.CURDIR}
CFLAGS+=-DXO_ENCODERDIR=\"${LIBDIR}/libxo/encoder\"

INCS=	xo.h xo_encoder.h
INCSDIR=${INCLUDEDIR}/libxo

LIBADD=	util

WARNS?= 5

.include <bsd.lib.mk>
