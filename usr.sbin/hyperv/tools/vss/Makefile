DIRDEPS = lib/libc

.include <bsd.own.mk>

HV_VSS_DAEMON_DISTDIR?= ${SRCTOP}/contrib/hyperv/tools
.PATH: ${HV_VSS_DAEMON_DISTDIR}

PACKAGE=hyperv-tools
PROG= 	hv_vss_daemon

CFLAGS+=	-I${SRCTOP}/sys/dev/hyperv/utilities

.include <bsd.prog.mk>
