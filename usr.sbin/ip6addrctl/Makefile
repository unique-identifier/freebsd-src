.include <src.opts.mk>

PACKAGE=	runtime
PROG=	ip6addrctl

.if ${MK_JAIL} != "no"
CFLAGS+= -DJAIL
LIBADD+= jail
.endif

.include <bsd.prog.mk>
