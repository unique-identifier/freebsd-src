PACKAGE=pmc
LIB_CXX=pmc
SRCS=	libpmc.c pmclog.c libpmc_pmu_util.c libpmc_json.cc
INCS=	pmc.h pmclog.h pmcformat.h

CFLAGS+= -I${SRCTOP}/${RELDIR:H}/libpmcstat

.if ${MACHINE_CPUARCH} == "aarch64"
EVENT_ARCH="arm64"
.elif ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386"
EVENT_ARCH="x86"
.elif ${MACHINE_CPUARCH} == "powerpc" && ${MACHINE_ARCH:Mpowerpc64*} != ""
EVENT_ARCH="powerpc"
.else
# This will generate an empty events table
EVENT_ARCH="none"
.endif

.if ${MK_DIRDEPS_BUILD} == "yes"
# avoid circular dependency
GENDIRDEPS_FILTER+= N${RELDIR:H}/libpmcstat
JEVENTS?= ${HOST_OBJTOP}/${RELDIR}/pmu-events/jevents
.else
JEVENTS= ${BTOOLSPATH:U.}/pmu-events/jevents

# This file is built in a subdirectory so never try to rebuild it here.
${JEVENTS}: .PHONY
.if make(*clean*)
SUBDIR+= pmu-events
.endif
.endif

libpmc_events.c: ${JEVENTS} .META
	${JEVENTS} ${EVENT_ARCH} ${.CURDIR}/pmu-events/arch ${.TARGET}.tmp
	if [ ! -e ${.TARGET} ] || ! cmp -s ${.TARGET} ${.TARGET}.tmp; then \
		mv -f ${.TARGET}.tmp ${.TARGET}; \
	fi
CLEANFILES+=	libpmc_events.c libpmc_events.c.tmp
SRCS+=	libpmc_events.c

WARNS?=	3

CFLAGS+= -I${.CURDIR} -I${SRCTOP}/sys
CWARNFLAGS.gcc+= -Wno-shadow -Wno-cast-align

# PMC-dependent manual pages

# Class aliases

.include <bsd.lib.mk>
