PROG=	mpsutil
SRCS=	mps_cmd.c mps_debug.c mps_flash.c mps_set.c mps_show.c mps_slot.c mpsutil.c

WARNS?= 3

LINKS=	${BINDIR}/mpsutil ${BINDIR}/mprutil

CFLAGS+= -I${SRCTOP}/sys -I. -DUSE_MPT_IOCTLS

# Here be dragons
.ifdef DEBUG
CFLAGS+= -DDEBUG
.endif

.include <bsd.prog.mk>
