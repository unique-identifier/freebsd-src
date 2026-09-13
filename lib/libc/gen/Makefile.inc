# machine-independent gen sources
.PATH: ${LIBC_SRCTOP}/${LIBC_ARCH}/gen ${LIBC_SRCTOP}/gen ${SRCTOP}/etc

CONFS+=	group master.passwd shells
CONFSMODE_master.passwd=	600
CONFSPACKAGE=   runtime

SRCS+= \
	__pthread_mutex_init_calloc_cb_stub.c \
	__xuname.c \
	_once_stub.c \
	_pthread_stubs.c \
	_rand48.c \
	_spinlock_stub.c \
	_thread_init.c \
	aio_read2.c \
	aio_write2.c \
	alarm.c \
	arc4random.c \
	arc4random-compat.c \
	arc4random_uniform.c \
	assert.c \
	basename.c \
	basename_compat.c \
	cap_sandboxed.c \
	check_utility_compat.c \
	clock.c \
	clock_getcpuclockid.c \
	closedir.c \
	confstr.c \
	cpuset_alloc.c \
	cpuset_free.c \
	crypt.c \
	ctermid.c \
	daemon.c \
	devname.c \
	devname-compat11.c \
	dirfd.c \
	dirname.c \
	dirname_compat.c \
	disklabel.c \
	dlfcn.c \
	drand48.c \
	dup3.c \
	elf_utils.c \
	erand48.c \
	err.c \
	errlst.c \
	eventfd.c \
	exec.c \
	exect.c \
	fdevname.c \
	fdopendir.c \
	feature_present.c \
	fmtcheck.c \
	fmtmsg.c \
	fnmatch.c \
	fpclassify.c \
	frexp.c \
	fstab.c \
	ftok.c \
	fts.c \
	fts-compat.c \
	fts-compat11.c \
	ftw.c \
	ftw-compat11.c \
	getbootfile.c \
	getbsize.c \
	getcap.c \
	getcwd.c \
	getdomainname.c \
	getentropy.c \
	getgrent.c \
	getgrouplist.c \
	gethostname.c \
	getloadavg.c \
	getlogin.c \
	getmntinfo.c \
	getmntinfo-compat11.c \
	getnetgrent.c \
	getosreldate.c \
	getpeereid.c \
	getprogname.c \
	getpwent.c \
	getttyent.c \
	getusershell.c \
	getutxent.c \
	getvfsbyname.c \
	glob.c \
	glob-compat11.c \
	initgroups.c \
	inotify.c \
	isatty.c \
	isinf.c \
	isnan.c \
	jrand48.c \
	kqueue1.c \
	lcong48.c \
	libc_dlopen.c \
	libc_interposing_table.c  \
	lrand48.c \
	memalign.c \
	memfd_create.c \
	mrand48.c \
	nftw.c \
	nftw-compat11.c \
	nice.c \
	nlist.c \
	nrand48.c \
	opendir.c \
	opendir2.c \
	pause.c \
	pmadvise.c \
	popen.c \
	posix_spawn.c \
	psignal.c \
	pututxline.c \
	pw_scan.c \
	raise.c \
	readdir.c \
	readdir-compat11.c \
	readpassphrase.c \
	rewinddir.c \
	scandir.c \
	scandir_b.c \
	scandir-compat11.c \
	sched_getaffinity.c \
	sched_setaffinity.c \
	seed48.c \
	seekdir.c \
	semctl.c \
	setdomainname.c \
	sethostname.c \
	setjmperr.c \
	setmode.c \
	setproctitle.c \
	setprogname.c \
	sig2str.c \
	siginterrupt.c \
	siglist.c \
	signal.c \
	sigsetops.c \
	sleep.c \
	srand48.c \
	statvfs.c \
	stringlist.c \
	strtofflags.c \
	sysconf.c \
	sysctl.c \
	sysctlbyname.c \
	sysctlnametomib.c \
	syslog.c \
	telldir.c \
	termios.c \
	time.c \
	times.c \
	timespec_get.c \
	timespec_getres.c \
	timezone.c \
	tls.c \
	ttyname.c \
	ttyslot.c \
	ualarm.c \
	uexterr_format.c \
	uexterr_gettext.c \
	ulimit.c \
	uname.c \
	unvis-compat.c \
	usleep.c \
	utime.c \
	utxdb.c \
	valloc.c \
	wordexp.c

.if ${COMPILER_FEATURES:Mblocks}
CFLAGS.fts.c= -fblocks
CFLAGS.glob.c= -fblocks
.endif

CFLAGS.arc4random.c= -I${SRCTOP}/sys -I${SRCTOP}/sys/crypto/chacha20

CFLAGS.sysconf.c= -I${SRCTOP}/contrib/tzcode

CFLAGS.dlfcn.c= ${RTLD_HDRS}
CFLAGS.tls.c= ${RTLD_HDRS}

.PATH: ${SRCTOP}/contrib/libc-pwcache
SRCS+=	pwcache.c pwcache.h

.PATH: ${SRCTOP}/contrib/libc-vis
CFLAGS+=	-I${SRCTOP}/contrib/libc-vis
SRCS+=	unvis.c vis.c

MISRCS+=modf.c

CANCELPOINTS_SRCS=sem.c sem_new.c
.for src in ${CANCELPOINTS_SRCS}
SRCS+=cancelpoints_${src}
CLEANFILES+=cancelpoints_${src}
cancelpoints_${src}: ${LIBC_SRCTOP}/gen/${src} .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}
.endfor

SYM_MAPS+=${LIBC_SRCTOP}/gen/Symbol.map

# machine-dependent gen sources
.sinclude "${LIBC_SRCTOP}/${LIBC_ARCH}/gen/Makefile.inc"

.include <src.tools.mk>

afterinstallconfig: install-passwd
install-passwd: .PHONY
	${PWD_MKDB_CMD} -i -p -d ${DESTDIR}/etc ${DESTDIR}/etc/master.passwd
.if defined(NO_ROOT) && defined(METALOG)
	( \
		echo ".${DISTBASE}/etc/pwd.db type=file uname=root gname=wheel mode=0644"; \
		echo ".${DISTBASE}/etc/spwd.db type=file uname=root gname=wheel mode=0600"; \
		echo ".${DISTBASE}/etc/passwd type=file uname=root gname=wheel mode=0644"; \
	) | cat -l >> ${METALOG}
.endif
