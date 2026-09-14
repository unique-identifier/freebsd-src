# $Whistle: Makefile,v 1.5 1999/01/24 06:48:37 archie Exp $

SYSDIR?=${SRCTOP}/sys
.include "${SYSDIR}/conf/kern.opts.mk"

SUBDIR=	${_bluetooth} \
	bpf \
	bridge \
	car \
	checksum \
	cisco \
	device \
	echo \
	eiface \
	etf \
	ether \
	ether_echo \
	frame_relay \
	gif \
	gif_demux \
	hole \
	hub \
	iface \
	ip_input \
	ipfw \
	ksocket \
	lmi \
	macfilter \
	nat \
	netflow \
	netgraph \
	one2many \
	patch \
	pipe \
	rfc1490 \
	socket \
	source \
	split \
	tag \
	tcpmss \
	tee \
	tty \
	UI \
	vlan \
	vlan_rotate

.if ${MK_BLUETOOTH} != "no" || defined(ALL_MODULES)
_bluetooth=	bluetooth
.endif

.include <bsd.subdir.mk>
