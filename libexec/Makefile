.include <src.opts.mk>

.include <bsd.compat.pre.mk>

SUBDIR=	${_atf} \
	${_atrun} \
	${_blocklistd-helper} \
	flua \
	getty \
	${_hyperv} \
	${_pppoed} \
	rc \
	${_rlogind} \
	rpc.rquotad \
	rpc.rstatd \
	rpc.rusersd \
	rpc.rwalld \
	rpc.sprayd \
	${_rshd} \
	${_rtld-elf} \
	save-entropy \
	${_nuageinit} \
	${_tests} \
	ulog-helper

.if ${MK_AT} != "no"
_atrun=		atrun
.endif

.if ${MK_BLOCKLIST} != "no"
_blocklistd-helper+=	blocklistd-helper
.endif

.if ${MK_BOOTPD} != "no"
SUBDIR+=	bootpd
.endif

.if ${MK_HYPERV} != "no"
_hyperv+=	hyperv
.endif

.if ${MK_NETGRAPH} != "no"
_pppoed=	pppoed
.endif

.if !defined(NO_PIC) && !defined(NO_RTLD)
_rtld-elf=	rtld-elf
.for LIBCOMPAT libcompat in ${_ALL_LIBCOMPATS_libcompats}
SUBDIR.${MK_LIB${LIBCOMPAT}}+=	rtld-elf${libcompat}
.endfor
.endif

.if ${MK_RBOOTD} != "no"
SUBDIR+=	rbootd
.endif

.if ${MK_TCP_WRAPPERS} != "no"
SUBDIR+=	tcpd
.endif

.if ${MK_TESTS} != "no"
_tests=		tests
.endif

.if ${MK_TESTS_SUPPORT} != "no"
_atf=		atf
.endif

.if ${MK_NUAGEINIT} != "no"
_nuageinit=	nuageinit
.endif

.include <bsd.arch.inc.mk>

.include <bsd.subdir.mk>
