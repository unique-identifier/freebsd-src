.include <src.opts.mk>

PACKAGE=	fetch

LIB=		fetch
CFLAGS+=	-I.
SRCS=		fetch.c common.c ftp.c http.c file.c \
		ftperr.h httperr.h
INCS=		fetch.h
CLEANFILES=	ftperr.h httperr.h

.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+=	-DINET6
.endif

.if ${MK_OPENSSL} != "no"
CFLAGS+=	-DWITH_SSL
CFLAGS+=	-DOPENSSL_API_COMPAT=0x10100000L
LIBADD+=	ssl crypto
.else
LIBADD+=	md
.endif

CFLAGS+=	-DFTP_COMBINE_CWDS

SHLIB_MAJOR=    6

ftperr.h: ftp.errors ${.CURDIR}/Makefile
	@echo "static struct fetcherr ftp_errlist[] = {" > ${.TARGET}
	@cat ${.CURDIR}/ftp.errors \
	  | grep -v ^# \
	  | sort \
	  | while read NUM CAT STRING; do \
	    echo "    { $${NUM}, FETCH_$${CAT}, \"$${STRING}\" },"; \
	  done >> ${.TARGET}
	@echo "    { -1, FETCH_UNKNOWN, \"Unknown FTP error\" }" >> ${.TARGET}
	@echo "};" >> ${.TARGET}

httperr.h: http.errors ${.CURDIR}/Makefile
	@echo "static struct fetcherr http_errlist[] = {" > ${.TARGET}
	@cat ${.CURDIR}/http.errors \
	  | grep -v ^# \
	  | sort \
	  | while read NUM CAT STRING; do \
	    echo "    { $${NUM}, FETCH_$${CAT}, \"$${STRING}\" },"; \
	  done >> ${.TARGET}
	@echo "    { -1, FETCH_UNKNOWN, \"Unknown HTTP error\" }" >> ${.TARGET}
	@echo "};" >> ${.TARGET}

.include <bsd.lib.mk>
