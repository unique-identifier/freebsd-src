# stdio sources
.PATH: ${LIBC_SRCTOP}/stdio

SRCS+=	_flock_stub.c asprintf.c clrerr.c dprintf.c \
	fclose.c fcloseall.c fdopen.c \
	feof.c ferror.c fflush.c fgetc.c fgetln.c fgetpos.c fgets.c fgetwc.c \
	fgetwln.c fgetws.c \
	fileno.c findfp.c flags.c fmemopen.c fopen.c \
	fopencookie.c fprintf.c fpurge.c \
	fputc.c fputs.c \
	fputwc.c fputws.c fread.c freopen.c fscanf.c fseek.c fsetpos.c \
	ftell.c funopen.c fvwrite.c fwalk.c fwide.c fwprintf.c fwscanf.c \
	fwrite.c getc.c getchar.c getdelim.c getline.c \
	gets.c gets_s.c getw.c getwc.c getwchar.c makebuf.c mktemp.c \
	open_memstream.c open_wmemstream.c \
	perror.c printf.c printf-pos.c putc.c putchar.c \
	puts.c putw.c putwc.c putwchar.c \
	refill.c remove.c rewind.c rget.c scanf.c setbuf.c setbuffer.c \
	setvbuf.c snprintf.c sprintf.c sscanf.c stdio.c swprintf.c swscanf.c \
	tempnam.c tmpfile.c \
	tmpnam.c ungetc.c ungetwc.c vasprintf.c vdprintf.c vfprintf.c \
	vfscanf.c \
	vfwprintf.c vfwscanf.c vprintf.c vscanf.c vsnprintf.c vsprintf.c \
	vsscanf.c \
	vswprintf.c vswscanf.c vwprintf.c vwscanf.c wbuf.c wprintf.c wscanf.c \
	wsetup.c

SRCS+=	xprintf.c xprintf_float.c xprintf_int.c xprintf_str.c
SRCS+=	xprintf_errno.c xprintf_hexdump.c xprintf_quote.c 
SRCS+=	xprintf_time.c xprintf_vis.c

SYM_MAPS+=	${LIBC_SRCTOP}/stdio/Symbol.map
