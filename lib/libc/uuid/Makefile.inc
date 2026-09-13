# DCE 1.1 UUID implementation sources

.PATH: ${LIBC_SRCTOP}/uuid

SRCS+=	uuid_compare.c uuid_create.c uuid_create_nil.c uuid_equal.c \
	uuid_from_string.c uuid_hash.c uuid_is_nil.c uuid_stream.c \
	uuid_to_string.c
SYM_MAPS+=	${LIBC_SRCTOP}/uuid/Symbol.map
