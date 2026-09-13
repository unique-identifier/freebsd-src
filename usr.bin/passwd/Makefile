.include <src.opts.mk>

PACKAGE	 = runtime
PROG	 = passwd
BINOWN	 = root
BINMODE	 = 4555
PRECIOUSPROG=
LIBADD   = pam
.if ${MK_NIS} != "no"
SYMLINKS = passwd ${BINDIR}/yppasswd
.endif

beforeinstall:
.for i in passwd yppasswd
	[ ! -e ${DESTDIR}${BINDIR}/$i ] || \
		chflags noschg ${DESTDIR}${BINDIR}/$i || true
.endfor

.include <bsd.prog.mk>
