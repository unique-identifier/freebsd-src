_spath=	${SRCTOP}/contrib/ofed/libibverbs
.PATH: ${_spath}

LIB=		ibverbs
SHLIB_MAJOR=	1
SHLIBDIR?=	/lib
VERSION_MAP=	${_spath}/libibverbs.map

CFLAGS+= -I${_spath}

SRCS= \
cmd.c \
compat-1_0.c \
device.c \
enum_strs.c \
init.c \
marshall.c \
memory.c \
sysfs.c \
verbs.c

.include <bsd.lib.mk>
