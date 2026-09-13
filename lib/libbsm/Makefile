PACKAGE=	audit
LIB_PACKAGE=

OPENBSMDIR=	${SRCTOP}/contrib/openbsm
_LIBBSMDIR=	${OPENBSMDIR}/libbsm

LIB=		bsm
SHLIB_MAJOR=	3

.PATH:		${_LIBBSMDIR}
.PATH:		${OPENBSMDIR}/bsm

SRCS=	bsm_audit.c							\
	bsm_class.c							\
	bsm_control.c							\
	bsm_domain.c							\
	bsm_errno.c							\
	bsm_event.c							\
	bsm_fcntl.c							\
	bsm_flags.c							\
	bsm_io.c							\
	bsm_mask.c							\
	bsm_notify.c							\
	bsm_socket_type.c						\
	bsm_token.c							\
	bsm_user.c							\
	bsm_wrappers.c

#
# Must use BSM include files from within the contrib area, not the system.
#
CFLAGS+=	-I${OPENBSMDIR} -I${_LIBBSMDIR}

WARNS?=		1

INCS=		audit_uevents.h libbsm.h
INCSDIR=	${INCLUDEDIR}/bsm

#
# It seems like maybe some of these should be installed separately, since
# they're not all libbsm parts.
#

.include <bsd.lib.mk>

# Disable -Wcast-align.  Casting sa_local in au_to_socket_ex triggers this
# warning, but it's ok because sa_local must've originally pointed to a
# sockaddr_in or sockaddr_in6 anyway.
# Better would be to disable this warning in just that one function, but GCC
# 4.2 can't do that :( .
CWARNFLAGS.bsm_token.c+=	-Wno-cast-align
