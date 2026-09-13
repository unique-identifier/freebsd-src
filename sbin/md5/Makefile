PACKAGE=runtime
PROG=	md5

LINKS=	${BINDIR}/md5 ${BINDIR}/md5sum \
	${BINDIR}/md5 ${BINDIR}/rmd160 \
	${BINDIR}/md5 ${BINDIR}/rmd160sum \
	${BINDIR}/md5 ${BINDIR}/sha1 \
	${BINDIR}/md5 ${BINDIR}/sha1sum \
	${BINDIR}/md5 ${BINDIR}/sha224 \
	${BINDIR}/md5 ${BINDIR}/sha224sum \
	${BINDIR}/md5 ${BINDIR}/sha256 \
	${BINDIR}/md5 ${BINDIR}/sha256sum \
	${BINDIR}/md5 ${BINDIR}/sha384 \
	${BINDIR}/md5 ${BINDIR}/sha384sum \
	${BINDIR}/md5 ${BINDIR}/sha512 \
	${BINDIR}/md5 ${BINDIR}/sha512sum \
	${BINDIR}/md5 ${BINDIR}/sha512t224 \
	${BINDIR}/md5 ${BINDIR}/sha512t224sum \
	${BINDIR}/md5 ${BINDIR}/sha512t256 \
	${BINDIR}/md5 ${BINDIR}/sha512t256sum \
	${BINDIR}/md5 ${BINDIR}/skein256 \
	${BINDIR}/md5 ${BINDIR}/skein256sum \
	${BINDIR}/md5 ${BINDIR}/skein512 \
	${BINDIR}/md5 ${BINDIR}/skein512sum \
	${BINDIR}/md5 ${BINDIR}/skein1024 \
	${BINDIR}/md5 ${BINDIR}/skein1024sum

# md5 can also emulate the shasum script that comes with Perl, except
# that, in bits input mode, it can only handle input lengths that are
# a multiple of 8 (see manual page).
#LINKS+= ${BINDIR}/md5 ${BINDIR}/shasum
#MLINKS+= md5.1 shasum.1

LIBADD=	md

.include <src.opts.mk>

.if ${MK_CASPER} != "no" && !defined(RESCUE) && !defined(BOOTSTRAPPING)
# Avoid depending on capsicum during bootstrap. caph_limit_stdout() is not
# available when building for Linux/MacOS or older FreeBSD hosts.
# We need to bootstrap md5 when building on Linux since the md5sum command there
# produces different output.
CFLAGS+=-DHAVE_CAPSICUM
CFLAGS+=-DWITH_CASPER
LIBADD+=	casper
LIBADD+=	cap_fileargs
.endif

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
