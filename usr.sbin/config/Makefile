SRCDIR:=${.PARSEDIR:tA}

PACKAGE= toolchain
PROG_CXX=	config
SRCS=	config.y main.cc lang.l mkmakefile.cc mkheaders.c \
	mkoptions.cc y.tab.h kernconf.c

FILE2C?=file2c

kernconf.c: kernconf.tmpl
	${FILE2C} 'char kernconfstr[] = {' ',0};' < \
	    ${SRCDIR}/kernconf.tmpl > kernconf.c

CFLAGS+= -I. -I${SRCDIR}

NO_WMISSING_VARIABLE_DECLARATIONS=

CLEANFILES+=	kernconf.c

mkmakefile.o: configvers.h

.include <bsd.prog.mk>
