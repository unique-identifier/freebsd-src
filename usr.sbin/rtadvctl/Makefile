#
.PATH:	${.CURDIR:H}/rtadvd

PROG=	rtadvctl

SRCS=	rtadvctl.c control.c control_client.c if.c timer_subr.c

CFLAGS+= -I${.CURDIR} -I${.CURDIR:H}/rtadvd
WARNS?=	1

.include <bsd.prog.mk>
