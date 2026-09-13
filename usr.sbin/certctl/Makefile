.include <src.opts.mk>

PACKAGE=	certctl
PROG=	certctl
LIBADD=	crypto
HAS_TESTS=
SUBDIR.${MK_TESTS}=	tests

.ifdef BOOTSTRAPPING
CFLAGS+=-DBOOTSTRAPPING
.endif

.include <bsd.prog.mk>
