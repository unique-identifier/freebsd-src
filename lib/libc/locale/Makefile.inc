# locale sources
.PATH: ${LIBC_SRCTOP}/${LIBC_ARCH}/locale ${LIBC_SRCTOP}/locale

SRCS+=	ascii.c big5.c btowc.c collate.c collcmp.c euc.c fix_grouping.c \
	gb18030.c gb2312.c gbk.c ctype.c isctype.c iswctype.c \
	ldpart.c lmessages.c lmonetary.c lnumeric.c localeconv.c mblen.c \
	mbrlen.c \
	mbrtowc.c mbsinit.c mbsnrtowcs.c \
	mbsrtowcs.c mbtowc.c mbstowcs.c \
	mskanji.c nextwctype.c nl_langinfo.c nomacros.c none.c rpmatch.c \
	rune.c \
	runetype.c setlocale.c setrunelocale.c \
	table.c \
	tolower.c toupper.c utf8.c wcrtomb.c wcsnrtombs.c \
	wcsrtombs.c wcsftime.c \
	wcstof.c wcstod.c \
	wcstoimax.c wcstol.c wcstold.c wcstoll.c \
	wcstombs.c \
	wcstoul.c wcstoull.c wcstoumax.c wctob.c wctomb.c wctrans.c wctype.c \
	wcwidth.c\
	xlocale.c

.if ${MK_ICONV} != "no"
SRCS+=	c16rtomb_iconv.c c32rtomb_iconv.c mbrtoc16_iconv.c mbrtoc32_iconv.c
.else
SRCS+=	c16rtomb.c c32rtomb.c mbrtoc16.c mbrtoc32.c
.endif

SYM_MAPS+=${LIBC_SRCTOP}/locale/Symbol.map
