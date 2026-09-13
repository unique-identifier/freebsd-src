_spath=	${SRCTOP}/contrib/ofed/librdmacm
.PATH: ${_spath}

SHLIBDIR?=	/usr/lib
LIB=		rdmacm
SHLIB_MAJOR=	1
CFLAGS+=	-I${_spath}

SRCS= \
acm.c \
addrinfo.c \
cma.c \
indexer.c

LIBADD=		ibverbs
VERSION_MAP=	${_spath}/librdmacm.map

.include <bsd.lib.mk>
