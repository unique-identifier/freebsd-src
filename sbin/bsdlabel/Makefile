.PATH: ${SRCTOP}/sys/geom

CONFS=	disktab
PACKAGE=runtime
PROG=	bsdlabel
SRCS=	bsdlabel.c geom_bsd_enc.c

.if ${MACHINE_CPUARCH} == "i386" || ${MACHINE_CPUARCH} == "amd64"
LINKS=	${BINDIR}/bsdlabel ${BINDIR}/disklabel
.endif

LIBADD=	geom

.include <bsd.prog.mk>
