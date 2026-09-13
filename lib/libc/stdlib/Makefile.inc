# machine-independent stdlib sources
.PATH: ${LIBC_SRCTOP}/${LIBC_ARCH}/stdlib ${LIBC_SRCTOP}/stdlib

MISRCS+= \
	C99_Exit.c \
	a64l.c \
	abort.c \
	abs.c \
	atexit.c \
	atof.c \
	atoi.c \
	atol.c \
	atoll.c \
	bsearch.c \
	bsearch_b.c \
	cxa_thread_atexit.c \
	cxa_thread_atexit_impl.c \
	div.c \
	exit.c \
	getenv.c \
	getopt.c \
	getopt_long.c \
	getsubopt.c \
	hcreate.c \
	hcreate_r.c \
	hdestroy_r.c \
	heapsort.c \
	heapsort_b.c \
	hsearch_r.c \
	imaxabs.c \
	imaxdiv.c \
	insque.c \
	l64a.c \
	labs.c \
	ldiv.c \
	llabs.c \
	lldiv.c \
	lsearch.c \
	memalignment.c \
	merge.c \
	mergesort_b.c \
	ptsname.c \
	qsort.c \
	qsort_r.c \
	qsort_r_compat.c \
	qsort_s.c \
	quick_exit.c \
	radixsort.c \
	rand.c \
	random.c \
	reallocarray.c \
	reallocf.c \
	realpath.c \
	recallocarray.c \
	remque.c \
	set_constraint_handler_s.c \
	strfmon.c \
	strtoimax.c \
	strtol.c \
	strtold.c \
	strtoll.c \
	strtoq.c \
	strtoul.c \
	strtonum.c \
	strtoull.c \
	strtoumax.c \
	strtouq.c \
	system.c \
	tdelete.c \
	tdestroy.c \
	tfind.c \
	tsearch.c \
	twalk.c

CFLAGS.qsort.c+= -Wsign-compare

# Work around an issue on case-insensitive file systems.
# libc has both _Exit.c and _exit.s and they both yield
# _exit.o (case insensitively speaking).
CLEANFILES+=C99_Exit.c
C99_Exit.c: ${LIBC_SRCTOP}/stdlib/_Exit.c .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}

SYM_MAPS+= ${LIBC_SRCTOP}/stdlib/Symbol.map

.include "${LIBC_SRCTOP}/stdlib/malloc/Makefile.inc"

# machine-dependent stdlib sources
.sinclude "${LIBC_SRCTOP}/${LIBC_ARCH}/stdlib/Makefile.inc"
