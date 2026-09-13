SHLIBDIR?=	/lib

.include <src.opts.mk>

PACKAGE=	zfs
LIB_PACKAGE=
LIB=		be
SHLIB_MAJOR=	1
SHLIB_MINOR=	0

SRCS=		be.c be_access.c be_error.c be_info.c
INCS=		be.h

LIBADD+= zfs
LIBADD+= nvpair
LIBADD+= spl
LIBADD+= zfsbootenv

CFLAGS+= -DIN_BASE -DHAVE_RPC_TYPES
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/include
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/include/os/freebsd
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libspl/include
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libspl/include/os/freebsd
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libzfs
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libzpool/include
CFLAGS+= -I${SRCTOP}/sys
CFLAGS+= -I${SRCTOP}/cddl/compat/opensolaris/include
CFLAGS+= -include ${SRCTOP}/sys/contrib/openzfs/include/os/freebsd/spl/sys/ccompile.h
CFLAGS+= -DHAVE_ISSETUGID -DHAVE_STRLCAT -DHAVE_STRLCPY
CFLAGS.be.c=		-Wno-cast-qual
CFLAGS.be_access.c=	-Wno-cast-qual
CFLAGS.be_error.c=	-Wno-cast-qual
CFLAGS.be_info.c=	-Wno-cast-qual

HAS_TESTS=	YES
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
