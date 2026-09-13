#
# Author: Harti Brandt <harti@freebsd.org>

.include <src.opts.mk>

CONTRIB=${SRCTOP}/contrib/bsnmp
.PATH: ${CONTRIB}/snmpd

CONFS=	snmpd.config
CONFSMODE=	600
PROG=	bsnmpd
SRCS=	main.c action.c config.c export.c trap.c trans_lsock.c
SRCS+=	trans_inet.c oid.h tree.c tree.h
XSYM=	snmpMIB begemotSnmpdModuleTable begemotSnmpd begemotTrapSinkTable \
	sysUpTime snmpTrapOID coldStart authenticationFailure \
	begemotSnmpdTransUdp begemotSnmpdTransLsock begemotSnmpdLocalPortTable \
	freeBSD freeBSDVersion begemotSnmpdTransInet
CLEANFILES= oid.h tree.c tree.h

FILESGROUPS= BMIBS DEFS

DEFSPACKAGE=	bsnmp
BMIBSPACKAGE=	bsnmp

BMIBS=	FOKUS-MIB.txt BEGEMOT-MIB.txt BEGEMOT-SNMPD.txt
BMIBSDIR= ${SHAREDIR}/snmp/mibs
DEFS=	tree.def
DEFSDIR= ${SHAREDIR}/snmp/defs

CFLAGS+= -I${CONTRIB}/lib -I${CONTRIB}/snmpd -I. -DUSE_LIBBEGEMOT
CFLAGS+= -DHAVE_STDINT_H -DHAVE_INTTYPES_H -DHAVE_ERR_H -DHAVE_STRLCPY
LIBADD=	begemot bsnmp

LDFLAGS+= -Wl,-export-dynamic

.if ${MK_OPENSSL} != "no"
CFLAGS+= -DHAVE_LIBCRYPTO
.endif

.if ${MK_TCP_WRAPPERS} != "no"
CFLAGS+=	-DUSE_TCPWRAPPERS
LIBADD+=	wrap
.endif

oid.h: tree.def Makefile
	gensnmptree -I${CONTRIB}/lib -e ${XSYM} < ${.ALLSRC:M*.def} > ${.TARGET}

.ORDER: tree.c tree.h
tree.h: .NOMETA
tree.c tree.h: tree.def
	gensnmptree -I${CONTRIB}/lib -l -f < ${.ALLSRC}

.include <bsd.prog.mk>
