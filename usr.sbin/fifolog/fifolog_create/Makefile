PROG=	fifolog_create

CFLAGS+= -I${.CURDIR:H}/lib

LIBADD=	util fifolog

regress:
	rm -f /tmp/fifolog.?
	./${PROG} /tmp/fifolog.0
	./${PROG} -s 10m /tmp/fifolog.1
	./${PROG} -l 1k /tmp/fifolog.2
	./${PROG} -r 1k /tmp/fifolog.3

.include <bsd.prog.mk>
