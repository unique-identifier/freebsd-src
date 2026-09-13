.include <src.opts.mk>

LIB=	procstat

SRCS=	cd9660.c	\
	common_kvm.c	\
	core.c		\
	libprocstat.c	\
	libprocstat_compat.c \
	msdosfs.c	\
	smbfs.c		\
	udf.c

VERSION_DEF=	${LIBCSRCDIR}/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map

INCS=		libprocstat.h
CFLAGS+=	-I. -I${.CURDIR} -D_KVM_VNODE
SHLIB_MAJOR=	1

LIBADD=		elf kvm util

.if ${MK_CDDL} != "no"
CFLAGS+=	-DLIBPROCSTAT_ZFS
SRCS+=	zfs.c
ZFSTOP=	${SRCTOP}/sys/contrib/openzfs
CFLAGS.zfs.c+=	-DIN_BASE
CFLAGS.zfs.c+=	-DHAVE_ISSETUGID
CFLAGS.zfs.c+=	-DZFS_DEBUG
CFLAGS.zfs.c+=	-I${ZFSTOP}/include
CFLAGS.zfs.c+=	-I${ZFSTOP}/lib/libspl/include
CFLAGS.zfs.c+=	-I${ZFSTOP}/lib/libspl/include/os/freebsd
CFLAGS.zfs.c+=	-I${ZFSTOP}/include/os/freebsd/zfs
CFLAGS.zfs.c+=	-I${ZFSTOP}/module/icp/include
CFLAGS.zfs.c+=	-I${SRCTOP}/sys
CFLAGS.zfs.c+=	-I${SRCTOP}/sys/modules/zfs
CFLAGS.zfs.c+=	-include ${ZFSTOP}/include/os/freebsd/spl/sys/ccompile.h
CFLAGS.zfs.c+=	-include ${SRCTOP}/sys/modules/zfs/zfs_config.h
CFLAGS.zfs.c+=	-Wno-cast-qual
.endif

.include <bsd.lib.mk>
