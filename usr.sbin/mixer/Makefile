.include <src.opts.mk>

PACKAGE=	sound

PROG=		mixer
SRCS=		${PROG}.c
LDFLAGS+=	-lmixer

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
