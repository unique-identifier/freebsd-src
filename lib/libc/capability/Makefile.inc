# capability sources
.PATH: ${SRCTOP}/sys/kern ${LIBC_SRCTOP}/capability

SRCS+=	subr_capability.c

SYM_MAPS+=	${LIBC_SRCTOP}/capability/Symbol.map
