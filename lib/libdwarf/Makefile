.include <bsd.own.mk>

PACKAGE=lib${LIB}
ELFTCDIR=${SRCTOP}/contrib/elftoolchain
SRCDIR=	${ELFTCDIR}/libdwarf

.PATH:	${SRCDIR}

LIB=	dwarf

SRCS=	\
	dwarf_abbrev.c		\
	dwarf_arange.c		\
	dwarf_attr.c		\
	dwarf_attrval.c		\
	dwarf_cu.c		\
	dwarf_dealloc.c		\
	dwarf_die.c		\
	dwarf_dump.c		\
	dwarf_errmsg.c		\
	dwarf_finish.c		\
	dwarf_form.c		\
	dwarf_frame.c		\
	dwarf_funcs.c		\
	dwarf_init.c		\
	dwarf_lineno.c		\
	dwarf_loclist.c		\
	dwarf_macinfo.c		\
	dwarf_pro_arange.c	\
	dwarf_pro_attr.c	\
	dwarf_pro_die.c		\
	dwarf_pro_expr.c	\
	dwarf_pro_finish.c	\
	dwarf_pro_frame.c	\
	dwarf_pro_funcs.c	\
	dwarf_pro_init.c	\
	dwarf_pro_lineno.c	\
	dwarf_pro_macinfo.c	\
	dwarf_pro_pubnames.c	\
	dwarf_pro_reloc.c	\
	dwarf_pro_sections.c	\
	dwarf_pro_types.c	\
	dwarf_pro_vars.c	\
	dwarf_pro_weaks.c	\
	dwarf_pubnames.c	\
	dwarf_pubtypes.c	\
	dwarf_ranges.c		\
	dwarf_reloc.c		\
	dwarf_sections.c	\
	dwarf_seterror.c	\
	dwarf_str.c		\
	dwarf_types.c		\
	dwarf_vars.c		\
	dwarf_weaks.c		\
	libdwarf.c		\
	libdwarf_abbrev.c	\
	libdwarf_arange.c	\
	libdwarf_attr.c		\
	libdwarf_die.c		\
	libdwarf_error.c	\
	libdwarf_elf_access.c	\
	libdwarf_elf_init.c	\
	libdwarf_frame.c	\
	libdwarf_info.c		\
	libdwarf_init.c		\
	libdwarf_lineno.c	\
	libdwarf_loc.c		\
	libdwarf_loclist.c	\
	libdwarf_macinfo.c	\
	libdwarf_nametbl.c	\
	libdwarf_ranges.c	\
	libdwarf_reloc.c	\
	libdwarf_rw.c		\
	libdwarf_sections.c	\
	libdwarf_str.c		\
	zlib_stub.c

INCS=		dwarf.h libdwarf.h

# This same hack is in lib/libelf/Makefile and usr.bin/readelf/Makefile
# We need to link against the correct version of these files. One
# solution is to include ../../sys in the include path. This causes
# problems when a header file in sys depends on a file in another
# part of the tree, e.g. a machine dependent header.
#
SRCS+=	sys/elf32.h sys/elf64.h sys/elf_common.h

GENSRCS=	dwarf_pubnames.c dwarf_pubtypes.c dwarf_weaks.c \
		dwarf_funcs.c dwarf_vars.c dwarf_types.c	\
		dwarf_pro_pubnames.c dwarf_pro_weaks.c		\
		dwarf_pro_funcs.c dwarf_pro_types.c		\
		dwarf_pro_vars.c
CLEANFILES=	${GENSRCS}
CLEANDIRS=	sys
CFLAGS+=	-I. -I${SRCDIR} -I${ELFTCDIR}/common -I${ELFTCDIR}/libelf

sys/elf32.h sys/elf64.h sys/elf_common.h: ${SRCTOP}/sys/${.TARGET} .NOMETA
	mkdir -p ${.OBJDIR}/sys
	ln -sf ${.ALLSRC} ${.TARGET}

LIBADD+=	elf z

SHLIB_MAJOR=	4

dwarf_pubnames.c:	dwarf_nametbl.m4 dwarf_pubnames.m4
dwarf_pubtypes.c:	dwarf_nametbl.m4 dwarf_pubtypes.m4
dwarf_weaks.c:		dwarf_nametbl.m4 dwarf_weaks.m4
dwarf_funcs.c:		dwarf_nametbl.m4 dwarf_funcs.m4
dwarf_vars.c:		dwarf_nametbl.m4 dwarf_vars.m4
dwarf_types.c:		dwarf_nametbl.m4 dwarf_types.m4
dwarf_pro_pubnames.c:	dwarf_pro_nametbl.m4 dwarf_pro_pubnames.m4
dwarf_pro_weaks.c:	dwarf_pro_nametbl.m4 dwarf_pro_weaks.m4
dwarf_pro_funcs.c:	dwarf_pro_nametbl.m4 dwarf_pro_funcs.m4
dwarf_pro_types.c:	dwarf_pro_nametbl.m4 dwarf_pro_types.m4
dwarf_pro_vars.c:	dwarf_pro_nametbl.m4 dwarf_pro_vars.m4

.include <bsd.lib.mk>

# Keep the .SUFFIXES line after the include of bsd.lib.mk
.SUFFIXES:	.m4 .c
.m4.c:
	m4 -D SRCDIR=${SRCDIR} ${M4FLAGS} ${.IMPSRC} > ${.TARGET}
