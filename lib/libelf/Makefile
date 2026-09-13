SHLIBDIR?= /lib

.include <bsd.own.mk>

ELFTCDIR=${SRCTOP}/contrib/elftoolchain
SRCDIR=	${ELFTCDIR}/libelf

.PATH:	${SRCDIR}

PACKAGE=	runtime
LIB=	elf

SRCS=	elf.c							\
	elf_begin.c						\
	elf_cntl.c						\
	elf_end.c elf_errmsg.c elf_errno.c			\
	elf_data.c						\
	elf_fill.c						\
	elf_flag.c						\
	elf_getarhdr.c						\
	elf_getarsym.c						\
	elf_getbase.c						\
	elf_getident.c						\
	elf_hash.c						\
	elf_kind.c						\
	elf_memory.c						\
	elf_next.c						\
	elf_open.c						\
	elf_rand.c						\
	elf_rawfile.c						\
	elf_phnum.c						\
	elf_shnum.c						\
	elf_shstrndx.c						\
	elf_scn.c						\
	elf_strptr.c						\
	elf_update.c						\
	elf_version.c						\
	gelf_cap.c						\
	gelf_chdr.c						\
	gelf_checksum.c						\
	gelf_dyn.c						\
	gelf_ehdr.c						\
	gelf_getclass.c						\
	gelf_fsize.c						\
	gelf_mips64el.c						\
	gelf_move.c						\
	gelf_phdr.c						\
	gelf_rel.c						\
	gelf_rela.c						\
	gelf_shdr.c						\
	gelf_sym.c						\
	gelf_syminfo.c						\
	gelf_symshndx.c						\
	gelf_xlate.c						\
	libelf_align.c						\
	libelf_allocate.c					\
	libelf_ar.c						\
	libelf_ar_util.c					\
	libelf_chdr.c						\
	libelf_checksum.c					\
	libelf_data.c						\
	libelf_ehdr.c						\
	libelf_elfmachine.c					\
	libelf_extended.c					\
	libelf_memory.c						\
	libelf_open.c						\
	libelf_phdr.c						\
	libelf_shdr.c						\
	libelf_xlate.c						\
	${GENSRCS}

INCS=		libelf.h gelf.h

# This same hack is in lib/libdwarf/Makefile and usr.bin/readelf/Makefile
# We need to link against the correct version of these files. One
# solution is to include ../../sys in the include path. This causes
# problems when a header file in sys depends on a file in another
# part of the tree, e.g. a machine dependent header.
#
SRCS+=	sys/elf32.h sys/elf64.h sys/elf_common.h

# Allow bootstrapping elftoolchain on Linux:
.if defined(BOOTSTRAPPING) && ${.MAKE.OS} == "Linux"
native-elf-format.h:
	${ELFTCDIR}/common/native-elf-format > ${.TARGET} || rm ${.TARGET}
SRCS+=	native-elf-format.h
.endif

GENSRCS=	libelf_fsize.c libelf_msize.c libelf_convert.c
CLEANFILES=	${GENSRCS}
CLEANDIRS=	sys
CFLAGS+=	-I. -I${SRCDIR} -I${ELFTCDIR}/common

sys/elf32.h sys/elf64.h sys/elf_common.h: ${SRCTOP}/sys/${.TARGET} .NOMETA
	mkdir -p ${.OBJDIR}/sys
	ln -sf ${.ALLSRC} ${.TARGET}

SHLIB_MAJOR=	2

.for E in 32 64
.endfor

VERSION_MAP=           ${SRCDIR}/Version.map

libelf_convert.c:	elf_types.m4 libelf_convert.m4
libelf_fsize.c:		elf_types.m4 libelf_fsize.m4
libelf_msize.c:		elf_types.m4 libelf_msize.m4

.include <bsd.lib.mk>

# Keep the .SUFFIXES line after the include of bsd.lib.mk
.SUFFIXES:	.m4 .c
.m4.c:
	m4 -D SRCDIR=${SRCDIR} ${M4FLAGS} ${.IMPSRC} > ${.TARGET}
