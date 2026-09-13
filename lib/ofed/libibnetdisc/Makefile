.include <src.opts.mk>

_spath=	${SRCTOP}/contrib/ofed/libibnetdisc
.PATH: ${_spath}

SHLIBDIR?=	/usr/lib
LIB_CXX=	ibnetdisc
SHLIB_MAJOR=	5

SRCS= \
chassis.c \
g_hash_table.cpp \
ibnetdisc.c \
ibnetdisc_cache.c \
query_smp.c

LIBADD=		osmcomp ibmad ibumad
CFLAGS+=	-DHAVE_CONFIG_H=1
CFLAGS+=	-I${_spath}
CFLAGS+=	-I${SYSROOT:U${DESTDIR}}/${INCLUDEDIR}/infiniband
VERSION_MAP=	${_spath}/libibnetdisc.map

.include <bsd.lib.mk>
