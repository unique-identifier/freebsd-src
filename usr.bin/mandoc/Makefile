.include <src.opts.mk>

# Retained only for bootstrap and native cross-tool builds until their
# remaining documentation consumers are removed.
.if defined(BOOTSTRAPPING) || defined(NXB_TARGET)
MANDOCDIR=	${SRCTOP}/contrib/mandoc
.PATH: ${MANDOCDIR}

PROG=	mandoc
MAN=
LINKS=	${BINDIR}/mandoc ${BINDIR}/whatis \
	${BINDIR}/mandoc ${BINDIR}/makewhatis \
	${BINDIR}/mandoc ${BINDIR}/apropos

LIBMAN_SRCS=	man.c \
		man_macro.c \
		man_validate.c

LIBMDOC_SRCS=	arch.c \
		att.c \
		lib.c \
		mdoc.c \
		mdoc_argv.c \
		mdoc_macro.c \
		mdoc_markdown.c \
		mdoc_state.c \
		mdoc_validate.c \
		st.c \

LIBROFF_SRCS=	eqn.c \
		roff.c \
		roff_escape.c \
		roff_html.c \
		roff_term.c \
		roff_validate.c \
		tbl.c \
		tbl_data.c \
		tbl_layout.c \
		tbl_opts.c \

LIB_SRCS=	${LIBMAN_SRCS} \
		${LIBMDOC_SRCS} \
		${LIBROFF_SRCS} \
		chars.c \
		mandoc.c \
		mandoc_aux.c \
		mandoc_dbg.c \
		mandoc_msg.c \
		mandoc_ohash.c \
		mandoc_xr.c \
		msec.c \
		preconv.c \
		read.c

HTML_SRCS=	eqn_html.c \
		html.c \
		man_html.c \
		mdoc_html.c \
		tbl_html.c

MAN_SRCS=	mdoc_man.c

TERM_SRCS=	eqn_term.c \
		man_term.c \
		mdoc_term.c \
		term.c \
		term_ascii.c \
		term_ps.c \
		term_tab.c \
		term_tag.c \
		tbl_term.c

DBM_SRCS=	dbm.c \
		dbm_map.c \
		mansearch.c

DBA_SRCS=	dba.c \
		dba_array.c \
		dba_read.c \
		dba_write.c \
		mandocdb.c

SRCS=		${LIB_SRCS} \
		${HTML_SRCS} \
		${MAN_SRCS} \
		${TERM_SRCS} \
		${DBM_SRCS} \
		${DBA_SRCS} \
		main.c \
		manpath.c \
		out.c \
		tag.c \
		tree.c

WARNS?=	3
CFLAGS+= -DHAVE_CONFIG_H \
	 -I${SRCTOP}/lib/libopenbsd/
# This can be removed after swtiching to newer gcc
CFLAGS.gcc+=	-Wno-format
LIBADD=	openbsd z

.endif # bootstrap or native cross-tools

.include <bsd.prog.mk>
