BSDDIALOG=	${SRCTOP}/contrib/bsddialog

.PATH:	${BSDDIALOG}/lib

LIB=	bsddialog
PRIVATELIB=	yes
SHLIB_MAJOR=	0
SRCS=	barbox.c \
	datebox.c \
	formbox.c \
	lib_util.c \
	lib_util.h \
	libbsddialog.c \
	menubox.c \
	messagebox.c \
	textbox.c \
	theme.c \
	timebox.c
INCS=	bsddialog.h \
	bsddialog_theme.h \
	bsddialog_progressview.h

LIBADD=	ncursesw tinfow
CFLAGS+=	-D_XOPEN_SOURCE_EXTENDED

.include <bsd.lib.mk>
