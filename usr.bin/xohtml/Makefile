.include <src.opts.mk>

LIBXOSRC=	${SRCTOP}/contrib/libxo

.PATH:	${LIBXOSRC}/xohtml

SCRIPTS= xohtml.sh

EXTERNAL_FILES = \
    external/jquery.js \
    external/jquery.qtip.css \
    external/jquery.qtip.js

INTERNAL_FILES = \
    xohtml.js \
    xohtml.css

FILES=          ${INTERNAL_FILES} ${EXTERNAL_FILES}
FILESDIR=       /usr/share/xohtml
FILESMODE=      ${NOBINMODE}

beforeinstall: mkfilesdir
mkfilesdir:
	test -d ${DESTDIR}${FILESDIR} \
	   || ${INSTALL} -d -o ${FILESOWN} -g ${FILESGRP} -m 755 ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
