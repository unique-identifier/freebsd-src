# gmon sources
.PATH: ${LIBC_SRCTOP}/gmon

SRCS+=	gmon.c mcount.c

SYM_MAPS+=${LIBC_SRCTOP}/gmon/Symbol.map

# mcount cannot be compiled with profiling
mcount.po: mcount.o
	cp mcount.o mcount.po
