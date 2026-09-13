# bootpd/Makefile

PROG=	bootpd
CFLAGS+= -DETC_ETHERS
CFLAGS+= -DSYSLOG -DDEBUG -DVEND_CMU

WARNS?=	2

SUBDIR= bootpgw tools

SRCS=	bootpd.c dovend.c readfile.c hash.c dumptab.c \
	 lookup.c getif.c hwaddr.c report.c tzone.c rtmsg.c

.include <bsd.prog.mk>
