CONFS=	locate.rc
PROG=	locate
SRCS=	util.c locate.c
CFLAGS+= -I${.CURDIR} -DMMAP
SCRIPTS=updatedb.sh mklocatedb.sh concatdb.sh

WARNS?=	2

SCRIPTSDIR=	${LIBEXECDIR}
.for script in ${SCRIPTS}
SCRIPTSNAME_${script}=	locate.${script:R}
.endfor

.include "../../Makefile.inc"
.include <bsd.prog.mk>
