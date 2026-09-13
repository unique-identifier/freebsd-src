.if ${MK_MACHDEP_OPTIMIZATIONS} != "no"
.PATH: ${LIBC_SRCTOP}/${LIBC_ARCH}/string
.endif
.PATH: ${LIBC_SRCTOP}/string
.PATH: ${SRCTOP}/sys/libkern

CFLAGS+= -I${LIBC_SRCTOP}/locale

# machine-independent string sources
MISRCS+=bcmp.c \
	bcopy.c \
	bzero.c \
	explicit_bzero.c \
	ffs.c \
	ffsl.c \
	ffsll.c \
	fls.c \
	flsl.c \
	flsll.c \
	memccpy.c \
	memchr.c \
	memrchr.c \
	memcmp.c \
	memcpy.c \
	memmem.c \
	memmove.c \
	mempcpy.c \
	memset.c \
	memset_s.c \
	memset_explicit.c \
	stpcpy.c \
	stpncpy.c \
	strcasecmp.c \
	strcat.c \
	strcasestr.c \
	strchr.c \
	strchrnul.c \
	strcmp.c \
	strcoll.c \
	strcpy.c\
	strcspn.c \
	strdup.c \
	strerror.c \
	strlcat.c \
	strlcpy.c \
	strlen.c \
	strmode.c \
	strncat.c \
	strncmp.c \
	strncpy.c \
	strndup.c \
	strnlen.c \
	strnstr.c \
	strpbrk.c \
	strrchr.c \
	strsep.c \
	strsignal.c \
	strspn.c \
	strstr.c \
	strtok.c \
	strverscmp.c \
	strxfrm.c \
	swab.c \
	timingsafe_bcmp.c \
	timingsafe_memcmp.c \
	wcpcpy.c \
	wcpncpy.c \
	wcscasecmp.c \
	wcscat.c \
	wcschr.c \
	wcscmp.c \
	wcscoll.c \
	wcscpy.c \
	wcscspn.c \
	wcsdup.c \
	wcslcat.c \
	wcslcpy.c \
	wcslen.c \
	wcsncasecmp.c \
	wcsncat.c \
	wcsncmp.c \
	wcsncpy.c \
	wcsnlen.c \
	wcspbrk.c \
	wcsrchr.c \
	wcsspn.c \
	wcsstr.c \
	wcstok.c \
	wcswidth.c \
	wcsxfrm.c \
	wmemchr.c \
	wmemcmp.c \
	wmemcpy.c \
	wmemmove.c \
	wmempcpy.c \
	wmemset.c

SYM_MAPS+=	${LIBC_SRCTOP}/string/Symbol.map

.if ${MK_ASAN} != "no"
# These source files deliberately read out of bounds since they assume that
# out-of-bounds memory accesses that don't cross pages are always legal.
# Note: While this is fine on x86, it does break when running with CHERI.
CFLAGS.strlen.c+=		-fno-sanitize=address
CFLAGS.strchrnul.c+=	-fno-sanitize=address
CFLAGS.memchr.c+=		-fno-sanitize=address
.endif

.if ${MK_MACHDEP_OPTIMIZATIONS} != "no"
# machine-dependent string sources
.sinclude "${LIBC_SRCTOP}/${LIBC_ARCH}/string/Makefile.inc"
.endif
