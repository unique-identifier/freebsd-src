#	Makefile.inc,v 1.2 1994/09/13 21:26:01 wollman Exp

.PATH:	${LIBC_SRCTOP}/stdtime ${SRCTOP}/contrib/tzcode

TZCODE_SRCS=	asctime.c difftime.c localtime.c
STDTIME_SRCS=	strftime.c strptime.c timelocal.c
SRCS+=		${TZCODE_SRCS} ${STDTIME_SRCS} time32.c

SYM_MAPS+=	${LIBC_SRCTOP}/stdtime/Symbol.map

.for src in ${TZCODE_SRCS} ${STDTIME_SRCS}
CFLAGS.${src}+=	-I${SRCTOP}/contrib/tzcode -include tzconfig.h
.endfor
.for src in ${STDTIME_SRCS}
CFLAGS.${src}+=	-I${LIBC_SRCTOP}/stdtime
.endfor

CFLAGS.localtime.c+= -DALL_STATE -DTHREAD_SAFE
.if ${MK_DETECT_TZ_CHANGES} != "no"
CFLAGS.localtime.c+= -DDETECT_TZ_CHANGES
CFLAGS.Version.map+= -DDETECT_TZ_CHANGES
.endif
