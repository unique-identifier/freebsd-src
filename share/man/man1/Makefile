.include <src.opts.mk>

MANGROUPS=	MAN

MANLINKS=	intro.1 introduction.1

MANGROUPS+=	RUNTIME
RUNTIME=	builtin.1 intro.1
RUNTIMEPACKAGE=	runtime

# Create MLINKS for Shell built in commands for which there are no userland
# utilities of the same name:
RUNTIMELINKS=\
	builtin.1 alias.1 \
	builtin.1 bg.1 \
	builtin.1 bind.1 \
	builtin.1 break.1 \
	builtin.1 case.1 \
	builtin.1 cd.1 \
	builtin.1 chdir.1 \
	builtin.1 command.1 \
	builtin.1 continue.1 \
	builtin.1 do.1 \
	builtin.1 done.1 \
	builtin.1 elif.1 \
	builtin.1 else.1 \
	builtin.1 esac.1 \
	builtin.1 eval.1 \
	builtin.1 exec.1 \
	builtin.1 exit.1 \
	builtin.1 export.1 \
	builtin.1 fc.1 \
	builtin.1 fg.1 \
	builtin.1 fi.1 \
	builtin.1 for.1 \
	builtin.1 getopts.1 \
	builtin.1 hash.1 \
	builtin.1 if.1 \
	builtin.1 jobid.1 \
	builtin.1 jobs.1 \
	builtin.1 keybinds.1 \
	builtin.1 read.1 \
	builtin.1 readonly.1 \
	builtin.1 return.1 \
	builtin.1 set.1 \
	builtin.1 setvar.1 \
	builtin.1 shift.1 \
	builtin.1 then.1 \
	builtin.1 times.1 \
	builtin.1 trap.1 \
	builtin.1 type.1 \
	builtin.1 ulimit.1 \
	builtin.1 umask.1 \
	builtin.1 unalias.1 \
	builtin.1 unset.1 \
	builtin.1 until.1 \
	builtin.1 wait.1 \
	builtin.1 while.1

.if ${MK_TESTS} != "no"
MANGROUPS+=	ATF
ATFTOP=		${SRCTOP}/contrib/atf
.PATH:		${ATFTOP}/doc
ATF=		atf-test-program.1
ATFPACKAGE=	atf
.endif

.include <bsd.prog.mk>
