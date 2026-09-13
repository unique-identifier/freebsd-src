#
#

OPENBSMDIR=${SRCTOP}/contrib/openbsm
.PATH: ${OPENBSMDIR}/bin/audit

CFLAGS+=	-I${OPENBSMDIR}

PACKAGE=audit
PROG=	audit

LIBADD=	bsm

WARNS?=	5

.include <bsd.prog.mk>
