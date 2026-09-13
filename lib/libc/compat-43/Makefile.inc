# compat-43 sources
.PATH: ${LIBC_SRCTOP}/${LIBC_ARCH}/compat-43 ${LIBC_SRCTOP}/compat-43

SRCS+=	gethostid.c getwd.c killpg.c sethostid.c setpgrp.c \
	setrgid.c setruid.c sigcompat.c

SYM_MAPS+=${LIBC_SRCTOP}/compat-43/Symbol.map
