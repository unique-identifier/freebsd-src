PACKAGE=	runtime

LIB=		cam
SHLIBDIR?=	/lib
SRCS=		camlib.c scsi_cmdparse.c scsi_all.c scsi_da.c scsi_sa.c cam.c \
		ata_all.c nvme_all.c nvme_util.c smp_all.c scsi_wrap.c
INCS=		camlib.h scsi_wrap.h

LIBADD=		sbuf

WARNS?=		2

.PATH:		${SRCTOP}/sys/cam \
		${SRCTOP}/sys/cam/ata \
		${SRCTOP}/sys/cam/nvme \
		${SRCTOP}/sys/cam/mmc \
		${SRCTOP}/sys/cam/scsi \
		${SRCTOP}/sys/dev/nvme

CFLAGS+=	-I${.CURDIR} -I${SRCTOP}/sys

SHLIB_MAJOR=	7

.include <src.opts.mk>

HAS_TESTS=
SUBDIR.${MK_TESTS}+=	tests

.include <bsd.lib.mk>
