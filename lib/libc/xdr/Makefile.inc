.PATH: ${LIBC_SRCTOP}/xdr ${LIBC_SRCTOP}/.
SRCS+=	xdr.c xdr_array.c xdr_float.c xdr_mem.c \
	xdr_rec.c xdr_reference.c xdr_sizeof.c \
	xdr_stdio.c

SYM_MAPS+=	${LIBC_SRCTOP}/xdr/Symbol.map
