.include <src.opts.mk>

PACKAGE=	toolchain
PROG_CXX=	llvm-ar

SRCDIR=		llvm/tools/llvm-ar
SRCS+=		llvm-ar-driver.cpp
SRCS+=		llvm-ar.cpp

LINKS+=		${BINDIR}/llvm-ar ${BINDIR}/llvm-ranlib

.if ${MK_LLVM_BINUTILS} != "no"
LINKS+=		${BINDIR}/llvm-ar ${BINDIR}/ar ${BINDIR}/llvm-ar ${BINDIR}/ranlib
.endif

.include "../llvm.prog.mk"
