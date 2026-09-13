LIB=	kvm

PACKAGE=	runtime
SHLIBDIR?= /lib
SHLIB_MAJOR=	7
CFLAGS+=-DNO__SCCSID -I${.CURDIR}

SRCS=	kvm.c kvm_cptime.c kvm_getloadavg.c \
	kvm_getswapinfo.c kvm_pcpu.c kvm_private.c kvm_proc.c kvm_vnet.c \
	kvm_minidump_aarch64.c \
	kvm_amd64.c kvm_minidump_amd64.c \
	kvm_arm.c kvm_minidump_arm.c \
	kvm_i386.c kvm_minidump_i386.c \
	kvm_powerpc.c kvm_powerpc64.c \
	kvm_minidump_riscv.c \
	kvm_minidump_powerpc64.c kvm_minidump_powerpc64_hpt.c
INCS=	kvm.h

LIBADD=	elf

.include <src.opts.mk>

HAS_TESTS=
SUBDIR.${MK_TESTS}=	tests

.include <bsd.lib.mk>
