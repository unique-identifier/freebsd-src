SHLIBDIR?= /lib

.include <src.opts.mk>

PACKAGE=	runtime

.PATH: ${SRCTOP}/lib/libc/gen # for pw_scan.c

LIB=	util
SHLIB_MAJOR= 10

SRCS=	_secure_path.c cpuset.c expand_number.c flopen.c fparseln.c \
	ftime.c getlocalbase.c gr_util.c \
	hexdump.c humanize_number.c kinfo_getfile.c \
	kinfo_getallproc.c kinfo_getproc.c kinfo_getvmmap.c \
	kinfo_getvmobject.c kld.c \
	login_auth.c login_cap.c \
	login_class.c login_crypt.c login_ok.c login_times.c login_tty.c \
	mntopts.c \
	pidfile.c property.c pty.c pw_scan.c pw_util.c quotafile.c \
	realhostname.c stub.c trimdomain.c uucplock.c
INCS=	libutil.h login_cap.h mntopts.h

CFLAGS+= -DNO__SCCSID

.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+= -DINET6
.endif

CFLAGS+= -I${.CURDIR} -I${SRCTOP}/lib/libc/gen/

VERSION_DEF=	${SRCTOP}/lib/libc/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map

HAS_TESTS=
SUBDIR.${MK_TESTS}+= tests

.include <bsd.lib.mk>
