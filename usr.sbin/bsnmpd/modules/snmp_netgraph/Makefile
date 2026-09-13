#
# Author: Harti Brandt <harti@freebsd.org>

MOD=	netgraph
SRCS=	snmp_netgraph.c
XSYM=	begemotNg

BMIBS=	BEGEMOT-NETGRAPH.txt
DEFS=	${MOD}_tree.def
INCS=	snmp_${MOD}.h

LIBADD=	netgraph

.include <bsd.snmpmod.mk>
