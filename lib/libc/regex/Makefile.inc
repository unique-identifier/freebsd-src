# regex sources
.PATH: ${LIBC_SRCTOP}/regex

CFLAGS+=-DPOSIX_MISTAKE

SRCS+=	regcomp.c regerror.c regexec.c regfree.c

SYM_MAPS+=${LIBC_SRCTOP}/regex/Symbol.map

# manpages only included in libc version
