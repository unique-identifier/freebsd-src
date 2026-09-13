PACKAGE=lib${LIB}

.include <src.opts.mk>

LIB=		execinfo
SHLIB_MAJOR=	1

.PATH:		${SRCTOP}/contrib/libexecinfo

INCS=		execinfo.h
SRCS=		backtrace.c symtab.c unwind.c
CFLAGS+=	-I${SRCTOP}/contrib/llvm-project/libunwind/include

LIBADD=		elf

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
