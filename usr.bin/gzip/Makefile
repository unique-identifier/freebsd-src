#	$NetBSD: Makefile,v 1.18 2013/11/13 11:12:24 pettai Exp $

.include <src.opts.mk>

PROG=		gzip

LIBADD=		z lzma zstd

.if ${MK_BZIP2_SUPPORT} != "no"
LIBADD+=	bz2
.else
CFLAGS+=	-DNO_BZIP2_SUPPORT
.endif

CFLAGS+=	-I${SRCTOP}/sys/contrib/zstd/lib

SCRIPTS=	gzexe zdiff zforce zmore znew

LINKS+=		${BINDIR}/gzip ${BINDIR}/gunzip \
		${BINDIR}/gzip ${BINDIR}/gzcat \
		${BINDIR}/gzip ${BINDIR}/zcat \
		${BINDIR}/zdiff ${BINDIR}/xzdiff \
		${BINDIR}/zdiff ${BINDIR}/zcmp

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.prog.mk>
