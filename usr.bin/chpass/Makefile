.include <src.opts.mk>

.PATH: ${SRCTOP}/lib/libc/gen

PROG=	chpass
SRCS=	chpass.c edit.c field.c pw_scan.c table.c util.c
BINOWN=	root
BINMODE=4555
PRECIOUSPROG=
#Some people need this, uncomment to activate
#CFLAGS+=-DRESTRICT_FULLNAME_CHANGE
CFLAGS+=-I${SRCTOP}/lib/libc/gen -I.

LIBADD=	crypt util

SYMLINKS=	chpass ${BINDIR}/chfn
SYMLINKS+=	chpass ${BINDIR}/chsh

beforeinstall:
.for i in chpass chfn chsh
.if exists(${DESTDIR}${BINDIR}/$i)
	-chflags noschg ${DESTDIR}${BINDIR}/$i
.endif
.endfor

.include <bsd.prog.mk>
