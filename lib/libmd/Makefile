SHLIBDIR?= /lib

.include <src.opts.mk>
.include <bsd.compiler.mk>

PACKAGE=	runtime
LIB=	md
SHLIB_MAJOR= 7
SRCS=	md4c.c md5c.c md4hl.c md5hl.c \
	rmd160c.c rmd160hl.c \
	sha0c.c sha0hl.c sha1c.c sha1hl.c \
	sha224hl.c sha256c.c sha256hl.c \
	sha384hl.c \
	sha512c.c sha512hl.c sha512t224hl.c sha512t256hl.c \
	skein.c skein_block.c \
	skein256hl.c skein512hl.c skein1024hl.c
INCS=	md4.h md5.h ripemd.h sha.h sha224.h sha256.h sha384.h sha512.h \
	sha512t.h skein.h skein_port.h skein_freebsd.h skein_iv.h

WARNS?=	0

VERSION_DEF=	${SRCTOP}/lib/libc/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map

CLEANFILES+=	md[245]hl.c md[245].ref mddriver \
		rmd160.ref rmd160hl.c rmddriver \
		sha0.ref sha0hl.c sha1.ref sha1hl.c shadriver \
		sha224.ref sha256.ref sha224hl.c sha256hl.c \
		sha384hl.c sha384.ref \
		sha512.ref sha512hl.c \
		sha512t224.ref sha512t224hl.c \
		sha512t256.ref sha512t256hl.c \
		skein256hl.c skein512hl.c skein1024hl.c \
		skein256.ref skein512.ref skein1024.ref \
		skeindriver

# Need src tree sys/md5.h for MD5FileChunk prototype on older systems.
SRCS+=		sys/md5.h
CLEANDIRS=	sys
CFLAGS+=	-I.
sys/md5.h: ${SRCTOP}/sys/${.TARGET} .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}

# Define WEAK_REFS to provide weak aliases for libmd symbols
#
# Note that the same sources are also used internally by libcrypt,
# in which case:
#   * macros are used to rename symbols to libcrypt internal names
#   * no weak aliases are generated
CFLAGS+= -I${.CURDIR} -I${SRCTOP}/sys/crypto/sha2
CFLAGS+= -I${SRCTOP}/sys/crypto/skein
CFLAGS+= -DWEAK_REFS
# unroll the 256 and 512 loops, half unroll the 1024
CFLAGS.skein_block.c+= -DSKEIN_LOOP=995
.PATH: ${.CURDIR}/${MACHINE_ARCH} ${SRCTOP}/sys/crypto/sha2
.PATH: ${SRCTOP}/sys/crypto/skein ${SRCTOP}/sys/crypto/skein/${MACHINE_ARCH}
.PATH: ${SRCTOP}/sys/crypto

USE_ASM_SOURCES?=1
.if defined(BOOTSTRAPPING) || ${MK_MACHDEP_OPTIMIZATIONS} == no
# Don't build ASM sources when bootstrapping to avoid toolchain dependencies
USE_ASM_SOURCES:=0
.endif

.if ${USE_ASM_SOURCES} != 0
.if exists(${MACHINE_ARCH}/md5block.S)
SRCS+=	md5block.S
CFLAGS+= -DMD5_ASM
.if exists(${MACHINE_ARCH}/md5dispatch.c)
SRCS+=  md5dispatch.c
.endif
.endif
.if exists(${MACHINE_ARCH}/sha1block.S)
SRCS+=	sha1block.S
CFLAGS+= -DSHA1_ASM
.if exists(${MACHINE_ARCH}/sha1dispatch.c)
SRCS+=  sha1dispatch.c
.endif
.endif
.if exists(${MACHINE_ARCH}/rmd160.S)
SRCS+=	rmd160.S
CFLAGS+= -DRMD160_ASM
.endif
.if exists(${MACHINE_ARCH}/skein_block_asm.S)
# Fully unroll all loops in the assembly optimized version
ACFLAGS+= -DSKEIN_LOOP=0
SRCS+= skein_block_asm.S
CFLAGS+= -DSKEIN_ASM -DSKEIN_USE_ASM=1792 # list of block functions to replace with assembly: 256+512+1024 = 1792
# 20201002 Add explict Makefile dependency for r366344 (reenabled assembly
# optimized version). SKEIN_USE_ASM determines which routines should come from
# the assembly vs C versions, and skein_block needs to be rebuilt if it changes.
skein_block.o skein_block.pico: Makefile
.endif
.if exists(${MACHINE_ARCH}/rmd160.S) || exists(${MACHINE_ARCH}/skein_block_asm.S)
ACFLAGS+= -DELF -Wa,--noexecstack
.endif
.if ${MACHINE_CPUARCH} == "aarch64"
SRCS+=	sha256c_arm64.c
CFLAGS+= -DARM64_SHA2
CFLAGS.sha256c_arm64.c+= -march=armv8-a+crypto
.if ${COMPILER_FEATURES:Maarch64-sha512}
SRCS+=	sha512c_arm64.c
CFLAGS+= -DARM64_SHA512
CFLAGS.sha512c_arm64.c+= -march=armv8.2-a+sha3
.endif # aarch64-sha512
.endif
.endif # ${USE_ASM_SOURCES} != 0

md4hl.c: mdXhl.c
	(echo '#define LENGTH 16'; \
		sed -e 's/mdX/md4/g' -e 's/MDX/MD4/g' ${.ALLSRC}) > ${.TARGET}

md5hl.c: mdXhl.c
	(echo '#define LENGTH 16'; \
		sed -e 's/mdX/md5/g' -e 's/MDX/MD5/g' ${.ALLSRC}) > ${.TARGET}

sha0hl.c: mdXhl.c
	(echo '#define LENGTH 20'; \
		sed -e 's/mdX/sha/g' -e 's/MDX/SHA_/g' -e 's/SHA__/SHA_/g' \
		${.ALLSRC}) > ${.TARGET}

sha1hl.c: mdXhl.c
	(echo '#define LENGTH 20'; \
		sed -e 's/mdX/sha/g' -e 's/MDX/SHA1_/g' -e 's/SHA1__/SHA1_/g' \
		${.ALLSRC}) > ${.TARGET}

sha224hl.c: mdXhl.c
	(echo '#define LENGTH 28'; \
		sed -e 's/mdX/sha224/g' -e 's/MDX/SHA224_/g'	\
			-e  's/SHA224__/SHA224_/g' \
		${.ALLSRC}) > ${.TARGET}

sha256hl.c: mdXhl.c
	(echo '#define LENGTH 32'; \
		sed -e 's/mdX/sha256/g' -e 's/MDX/SHA256_/g'	\
			-e  's/SHA256__/SHA256_/g' \
		${.ALLSRC}) > ${.TARGET}

sha384hl.c: mdXhl.c
	(echo '#define LENGTH 48'; \
		sed -e 's/mdX/sha384/g' -e 's/MDX/SHA384_/g'	\
			-e  's/SHA384__/SHA384_/g' \
		${.ALLSRC}) > ${.TARGET}

sha512hl.c: mdXhl.c
	(echo '#define LENGTH 64'; \
		sed -e 's/mdX/sha512/g' -e 's/MDX/SHA512_/g'	\
			-e  's/SHA512__/SHA512_/g' \
		${.ALLSRC}) > ${.TARGET}

sha512t224hl.c: mdXhl.c
	(echo '#define LENGTH 28'; \
		sed -e 's/mdX/sha512t/g' -e 's/MDX/SHA512_224_/g'	\
			-e  's/SHA512_224__/SHA512_224_/g' \
			-e 's/SHA512_224_CTX/SHA512_CTX/g' \
		${.ALLSRC}) > ${.TARGET}

sha512t256hl.c: mdXhl.c
	(echo '#define LENGTH 32'; \
		sed -e 's/mdX/sha512t/g' -e 's/MDX/SHA512_256_/g'	\
			-e  's/SHA512_256__/SHA512_256_/g' \
			-e 's/SHA512_256_CTX/SHA512_CTX/g' \
		${.ALLSRC}) > ${.TARGET}

rmd160hl.c: mdXhl.c
	(echo '#define LENGTH 20'; \
		sed -e 's/mdX/ripemd/g' -e 's/MDX/RIPEMD160_/g' \
			-e 's/RIPEMD160__/RIPEMD160_/g' \
			${.ALLSRC}) > ${.TARGET}

skein256hl.c: mdXhl.c
	(echo '#define LENGTH 32'; \
		sed -e 's/mdX/skein/g' -e 's/MDX/SKEIN256_/g'	\
			-e  's/SKEIN256__/SKEIN256_/g' \
		${.ALLSRC}) > ${.TARGET}

skein512hl.c: mdXhl.c
	(echo '#define LENGTH 64'; \
		sed -e 's/mdX/skein/g' -e 's/MDX/SKEIN512_/g'	\
			-e  's/SKEIN512__/SKEIN512_/g' \
		${.ALLSRC}) > ${.TARGET}

skein1024hl.c: mdXhl.c
	(echo '#define LENGTH 128'; \
		sed -e 's/mdX/skein/g' -e 's/MDX/SKEIN1024_/g'	\
			-e  's/SKEIN1024__/SKEIN1024_/g' \
		${.ALLSRC}) > ${.TARGET}

HAS_TESTS=
SUBDIR.${MK_TESTS}+=	tests

.include <bsd.lib.mk>
