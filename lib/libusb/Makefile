#
# Makefile for the FreeBSD specific LibUSB 2.0
#

LIB=		usb
SHLIB_MAJOR=	3
SHLIB_MINOR=	0
SRCS=		libusb20.c
SRCS+=		libusb20_desc.c
SRCS+=		libusb20_ugen20.c
INCS+=		libusb20.h
INCS+=		libusb20_desc.h
MKLINT=		no
NOGCCERROR=
PTHREAD_LIBS?=	-lpthread

WARNS?=		2

LIBADD=		pthread

# libusb 0.1 compat
INCS+=		usb.h
SRCS+=		libusb01.c

# libusb 1.0 compat
INCS+=		libusb.h
SRCS+=		libusb10.c
SRCS+=		libusb10_desc.c
SRCS+=		libusb10_hotplug.c
SRCS+=		libusb10_io.c

PCFILES=	libusb-0.1.pc libusb-1.0.pc libusb-2.0.pc
.for pcfile in ${PCFILES}
${pcfile}: ${pcfile}.in
	sed -e 's,@libdir@,${LIBDIR},g ; s,@sharedlibdir@,${SHLIBDIR},g ; \
		s,@includedir@,${INCLUDEDIR},g ;' ${.ALLSRC} > ${.TARGET}
.endfor
CLEANFILES+=	${PCFILES}

#
# Cross platform support
#
# Examples:
# make LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h
# make \
#   LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h \
#   DEBUG_FLAGS="-g"
#
# From Ubuntu 10.04:
# freebsd-make LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h \
#    PTHREAD_LIBS="-lpthread -lrt"
# freebsd-make \
#    LIBUSB_GLOBAL_INCLUDE_FILE=libusb_global_linux.h \
#    PTHREAD_LIBS="-lpthread -lrt"
#
#
.if defined(LIBUSB_GLOBAL_INCLUDE_FILE)
CFLAGS+=	-DLIBUSB_GLOBAL_INCLUDE_FILE=\"${LIBUSB_GLOBAL_INCLUDE_FILE}\"
CFLAGS+=	-DUSB_GLOBAL_INCLUDE_FILE=\"${LIBUSB_GLOBAL_INCLUDE_FILE}\"
CFLAGS+=	-I ../../sys
.endif

# LibUSB v1.0

# LibUSB v0.1

# LibUSB v2.0

.include <bsd.lib.mk>
