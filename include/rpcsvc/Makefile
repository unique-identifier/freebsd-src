.SUFFIXES: .x

RPCCOM=	RPCGEN_CPP=${CPP:Q} rpcgen -C

HDRS= key_prot.h klm_prot.h mount.h nfs_prot.h nlm_prot.h rex.h rnusers.h \
	rquota.h rstat.h rwall.h sm_inter.h spray.h bootparam_prot.h crypt.h
XFILES= bootparam_prot.x key_prot.x klm_prot.x mount.x nfs_prot.x \
	nlm_prot.x rex.x rnusers.x rquota.x rstat.x rwall.x sm_inter.x spray.x \
	crypt.x

CLEANFILES+= ${HDRS}

INCSGROUPS=	INCS RPCHDRS
INCS=		${XFILES} ${HDRS}
INCSDIR=	${INCLUDEDIR}/rpcsvc
RPCHDRS=	key_prot.h
RPCHDRSDIR=	${INCLUDEDIR}/rpc

.x.h:
	${RPCCOM} -h -DWANT_NFS3 ${.IMPSRC} -o ${.TARGET}

.include <bsd.prog.mk>
