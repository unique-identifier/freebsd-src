PACKAGE=	ufs
LIB_PACKAGE=

LIB=	ufs
SHLIBDIR?= /lib
SHLIB_MAJOR=	8

SRCS=	block.c cgroup.c gsb_crc32.c inode.c sblock.c type.c ffs_subr.c
SRCS+= ffs_tables.c
INCS=	libufs.h

.PATH:  ${SRCTOP}/sys/libkern ${SRCTOP}/sys/ufs/ffs

WARNS?=	2

CFLAGS+= -D_LIBUFS
.if defined(LIBUFS_DEBUG)
CFLAGS+= -D_LIBUFS_DEBUGGING
.endif
CFLAGS+= -I${.CURDIR}

.include <bsd.lib.mk>
