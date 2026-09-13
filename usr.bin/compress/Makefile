.include <src.opts.mk>

PROG=	compress
SRCS=	compress.c zopen.c
LINKS=	${BINDIR}/compress ${BINDIR}/uncompress

# XXX zopen is not part of libc
# MAN=zopen.3

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
