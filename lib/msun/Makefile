#  ====================================================
#  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
#
#  Developed at SunPro, a Sun Microsystems, Inc. business.
#  Permission to use, copy, modify, and distribute this
#  software is freely granted, provided that this notice
#  is preserved.
#  ====================================================
#
#

PACKAGE=	clibs
ARCH_SUBDIR=	${MACHINE_CPUARCH:S/i386/i387/}

.include "${ARCH_SUBDIR}/Makefile.inc"

.PATH:	${.CURDIR}/${ARCH_SUBDIR}
.if ${MACHINE_CPUARCH} == "i386" || ${MACHINE_CPUARCH} == "amd64"
.PATH:	${.CURDIR}/x86
CFLAGS+=	-I${.CURDIR}/x86
.endif

# long double format
.if ${LDBL_PREC} == 64
.PATH:  ${.CURDIR}/ld80
CFLAGS+=	-I${.CURDIR}/ld80
.elif ${LDBL_PREC} == 113
.PATH:  ${.CURDIR}/ld128
CFLAGS+=	-I${.CURDIR}/ld128 -I${SRCTOP}/contrib/arm-optimized-routines/math
.endif

CFLAGS+=	-I${.CURDIR}/${ARCH_SUBDIR}

.include <bsd.compiler.mk>
.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} >= 100000 && \
    (${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386")
# When using clang with x86_64 CPUs that support AVX, some floating point
# transformations may raise exceptions that would not have been raised by the
# original code. To avoid this, use the -fp-exception-behavior=maytrap flag,
# introduced in clang 10.0.0.
# See also: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=254911
CFLAGS+=	-ffp-exception-behavior=maytrap
.endif

# Tell the compiler we don't set errno in any of the math functions. This
# stops gcc from trying to generate a function call to set errno when using
# a builtin in the implementation
CFLAGS+=	-fno-math-errno

.PATH:	${.CURDIR}/bsdsrc
.PATH:	${.CURDIR}/src

LIB=	m
SHLIBDIR?= /lib
SHLIB_MAJOR= 5
WARNS?=	1
IGNORE_PRAGMA=
COMMON_SRCS= b_tgamma.c \
	e_acos.c e_acosf.c e_acosh.c e_acoshf.c e_asin.c e_asinf.c \
	e_atan2.c e_atan2f.c e_atanh.c e_atanhf.c e_cosh.c e_coshf.c e_exp.c \
	e_expf.c e_fmod.c e_fmodf.c e_gamma.c e_gamma_r.c e_gammaf.c \
	e_gammaf_r.c e_hypot.c e_hypotf.c e_j0.c e_j0f.c e_j1.c e_j1f.c \
	e_jn.c e_jnf.c e_lgamma.c e_lgamma_r.c e_lgammaf.c e_lgammaf_r.c \
	e_log.c e_log10.c e_log10f.c e_log2.c e_log2f.c e_logf.c \
	e_pow.c e_powf.c e_rem_pio2.c \
	e_rem_pio2f.c e_remainder.c e_remainderf.c e_scalb.c e_scalbf.c \
	e_sinh.c e_sinhf.c e_sqrt.c e_sqrtf.c fenv.c \
	k_cos.c k_cosf.c k_exp.c k_expf.c k_rem_pio2.c k_sin.c k_sinf.c \
	k_tan.c k_tanf.c \
	s_asinh.c s_asinhf.c s_atan.c s_atanf.c s_carg.c s_cargf.c s_cargl.c \
	s_cbrt.c s_cbrtf.c s_ceil.c s_ceilf.c s_clog.c s_clogf.c \
	s_copysign.c s_copysignf.c s_cos.c s_cosf.c \
	s_csqrt.c s_csqrtf.c s_erf.c s_erff.c \
	s_exp2.c s_exp2f.c s_expm1.c s_expm1f.c s_fabsf.c s_fdim.c \
	s_finite.c s_finitef.c \
	s_floor.c s_floorf.c s_fma.c s_fmaf.c \
	s_fmax.c s_fmaxf.c s_fmin.c \
	s_fminf.c s_frexp.c s_frexpf.c s_ilogb.c s_ilogbf.c \
	s_ilogbl.c s_isfinite.c s_isnan.c s_isnormal.c \
	s_llrint.c s_llrintf.c s_llround.c s_llroundf.c s_llroundl.c \
	s_log1p.c s_log1pf.c s_logb.c s_logbf.c s_lrint.c s_lrintf.c \
	s_lround.c s_lroundf.c s_lroundl.c s_modff.c \
	s_nan.c s_nearbyint.c s_nextafter.c s_nextafterf.c \
	s_nexttowardf.c s_remquo.c s_remquof.c \
	s_rint.c s_rintf.c s_round.c s_roundf.c \
	s_scalbln.c s_scalbn.c s_scalbnf.c s_signbit.c \
	s_signgam.c s_significand.c s_significandf.c s_sin.c \
	s_sincos.c s_sincosf.c s_sinf.c \
	s_tan.c s_tanf.c s_tanh.c s_tanhf.c s_tgammaf.c s_trunc.c s_truncf.c \
	w_cabs.c w_cabsf.c w_drem.c w_dremf.c

# IEEE-754 2008 and ISO/IEC TS 18661-4 half-cycle trignometric functions
COMMON_SRCS+= s_cospi.c s_cospif.c \
	s_sinpi.c s_sinpif.c \
	s_tanpi.c s_tanpif.c

# LIBCSRCDIR is defined lazily, so can't be used for exists() below
LIBC_SRCTOP=${SRCTOP}/lib/libc
# Location of fpmath.h and _fpmath.h

# Pick the current architecture directory for libc. In general, this is named
# MACHINE_CPUARCH, but some ABIs are different enough to require their own libc,
# so allow a directory named MACHINE_ARCH to override this (though treat
# powerpc64le and powerpc64 the same).
# Note: This is copied from libc/Makefile
M=${MACHINE_ARCH:S/powerpc64le/powerpc64/}
.if exists(${LIBC_SRCTOP}/${M})
LIBC_ARCH=${M}
.else
LIBC_ARCH=${MACHINE_CPUARCH}
.endif

CFLAGS+=	-I${.CURDIR}/src -I${LIBC_SRCTOP}/include \
		-I${LIBC_SRCTOP}/${LIBC_ARCH}
SYM_MAPS+=	${.CURDIR}/Symbol.map
SYM_MAPS+=	${.CURDIR}/${ARCH_SUBDIR}/Symbol.map

VERSION_DEF=	${LIBC_SRCTOP}/Versions.def
SYMBOL_MAPS=	${SYM_MAPS}

# C99 long double functions
COMMON_SRCS+=	s_copysignl.c s_fabsl.c s_llrintl.c s_lrintl.c s_modfl.c
.if ${LDBL_PREC} != 53
# If long double != double use these; otherwise, we alias the double versions.
COMMON_SRCS+=	b_tgammal.c catrigl.c \
	e_acoshl.c e_acosl.c e_asinl.c e_atan2l.c e_atanhl.c \
	e_coshl.c e_fmodl.c e_hypotl.c \
	e_lgammal.c e_lgammal_r.c e_powl.c \
	e_remainderl.c e_sinhl.c e_sqrtl.c \
	invtrig.c k_cosl.c k_sinl.c k_tanl.c \
	s_asinhl.c s_atanl.c s_cbrtl.c s_ceill.c s_cexpl.c \
	s_clogl.c s_cosl.c s_cospil.c s_cprojl.c \
	s_csqrtl.c s_erfl.c s_exp2l.c s_expl.c s_floorl.c s_fmal.c \
	s_fmaxl.c s_fminl.c s_frexpl.c s_logbl.c s_logl.c s_nanl.c \
	s_nextafterl.c s_nexttoward.c s_remquol.c s_rintl.c s_roundl.c \
	s_scalbnl.c s_sinl.c s_sincosl.c s_sinpil.c \
	s_tanhl.c s_tanl.c s_tanpil.c s_truncl.c w_cabsl.c
# Work around this warning from gcc:
#     lib/msun/ld80/e_powl.c:275:1: error: floating constant exceeds range of
#     'long double' [-Werror=overflow]
#     if( y >= LDBL_MAX )
# See also: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=130067
.if ${COMPILER_TYPE} == "gcc"
CFLAGS.e_powl.c+= -Wno-error=overflow
.endif
.endif

# C99 complex functions
COMMON_SRCS+=	catrig.c catrigf.c \
	s_ccosh.c s_ccoshf.c s_cexp.c s_cexpf.c \
	s_cimag.c s_cimagf.c s_cimagl.c \
	s_conj.c s_conjf.c s_conjl.c \
	s_cpow.c s_cpowf.c s_cpowl.c \
	s_cproj.c s_cprojf.c s_creal.c s_crealf.c s_creall.c \
	s_csinh.c s_csinhf.c s_ctanh.c s_ctanhf.c

# FreeBSD's C library supplies these functions (but note we still have s_frexp.c
# and s_isnan.c enabled above, so they are duplicated):
#COMMON_SRCS+=	s_fabs.c s_frexp.c s_isnan.c s_ldexp.c s_modf.c

# Exclude the generic versions of what we provide in the MD area.
.if defined(ARCH_SRCS) && "${MK_MACHDEP_OPTIMIZATIONS}" != no
.for i in ${ARCH_SRCS}
COMMON_SRCS:=  ${COMMON_SRCS:N${i:R}.c}
.endfor
.endif

SRCS=	${COMMON_SRCS} ${ARCH_SRCS}

INCS+=	fenv.h math.h

.include <src.opts.mk>

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.compiler.mk>
.if ${COMPILER_TYPE} == "clang" && ${COMPILER_VERSION} >= 120000
# Silence '#pragma FENV_ACCESS' is not supported on this target - ignored
CWARNFLAGS+=	-Wno-error=ignored-pragmas
.endif

.include <bsd.lib.mk>
