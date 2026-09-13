.include <src.opts.mk>

PACKAGE	 = runtime
PROG	 = passwd
BINOWN	 = root
BINMODE	 = 4555
PRECIOUSPROG=
LIBADD   = pam

beforeinstall:
.for i in passwd
	[ ! -e ${DESTDIR}${BINDIR}/$i ] || \
		chflags noschg ${DESTDIR}${BINDIR}/$i || true
.endfor

.include <bsd.prog.mk>
