#
#

.include <src.opts.mk>

OPENBSMDIR=${SRCTOP}/contrib/openbsm
.PATH: ${OPENBSMDIR}/bin/praudit

CFLAGS+=	-I${OPENBSMDIR}

PACKAGE=audit
PROG=	praudit

WARNS?=	3

LIBADD=	bsm

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
