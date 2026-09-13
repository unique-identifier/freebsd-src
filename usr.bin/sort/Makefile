.include <src.opts.mk>

PACKAGE= runtime
PROG=	sort
SRCS=	bwstring.c coll.c file.c mem.c radixsort.c sort.c vsort.c

.if ${MK_SORT_THREADS} != "no"
CFLAGS+= -DSORT_THREADS
LIBADD=	pthread md
.else
LIBADD=	md
.endif

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
