# Make `routed` for FreeBSD

PACKAGE=rip
PROG=	routed
SRCS=	if.c input.c main.c output.c parms.c radix.c rdisc.c table.c trace.c
WARNS?=	3
LIBADD=	md

SUBDIR= rtquery

.include <bsd.prog.mk>
