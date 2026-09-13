SHLIBDIR?=/lib

.include <src.opts.mk>

LIB=	ulog
SHLIB_MAJOR= 0
INCS=	ulog.h utempter.h
SRCS=	ulog.h ulog_login.c ulog_login_pseudo.c utempter.c

LIBADD=	md

VERSION_DEF= ${SRCTOP}/lib/libc/Versions.def
SYMBOL_MAPS= ${.CURDIR}/Symbol.map

.if ${MK_INSTALLLIB} != "no"
SYMLINKS+=libulog.a ${LIBDIR}/libutempter.a
.endif
.if !defined(NO_PIC)
SYMLINKS+=libulog.so ${LIBDIR}/libutempter.so
.endif

.include <bsd.lib.mk>
