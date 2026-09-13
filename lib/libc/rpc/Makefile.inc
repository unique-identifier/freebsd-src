.PATH: ${LIBC_SRCTOP}/rpc ${LIBC_SRCTOP}/.
CONFS+=	rpc/netconfig rpc/rpc
SRCS+=	auth_none.c auth_unix.c authunix_prot.c bindresvport.c clnt_bcast.c \
	clnt_dg.c clnt_generic.c clnt_perror.c clnt_raw.c clnt_simple.c \
	clnt_vc.c rpc_dtablesize.c getnetconfig.c getnetpath.c getrpcent.c \
	getrpcport.c mt_misc.c pmap_clnt.c pmap_getmaps.c pmap_getport.c \
	pmap_prot.c pmap_prot2.c pmap_rmt.c rpc_prot.c rpc_commondata.c \
	rpc_callmsg.c rpc_generic.c rpc_soc.c rpcb_clnt.c rpcb_prot.c \
	rpcb_st_xdr.c rpcsec_gss_stub.c svc.c svc_auth.c svc_dg.c \
	svc_auth_unix.c svc_generic.c svc_raw.c svc_run.c svc_simple.c \
	svc_vc.c svc_nl.c

# Secure-RPC
SRCS+=  auth_time.c auth_des.c authdes_prot.c des_crypt.c des_soft.c \
	crypt_client.c key_call.c key_prot_xdr.c getpublickey.c \
	svc_auth_des.c

# Resolver stuff
SRCS+=	netname.c netnamer.c rpcdname.c

# Misc Source
SRCS+=	rtime.c

# generated sources
SRCS+=  crypt_clnt.c crypt_xdr.c crypt.h

SYM_MAPS+=${LIBC_SRCTOP}/rpc/Symbol.map

CFLAGS+= -DBROKEN_DES -DPORTMAP -DDES_BUILTIN
CFLAGS+= -I${LIBC_SRCTOP}/rpc

CLEANFILES+= crypt_clnt.c crypt_xdr.c crypt.h

RPCDIR= ${SRCTOP}/include/rpcsvc
RPCGEN= RPCGEN_CPP=${CPP:Q} rpcgen -C

crypt_clnt.c: ${RPCDIR}/crypt.x crypt.h
	${RPCGEN} -l -o ${.TARGET} ${RPCDIR}/crypt.x

crypt_xdr.c: ${RPCDIR}/crypt.x crypt.h
	${RPCGEN} -c -o ${.TARGET} ${RPCDIR}/crypt.x

crypt.h: ${RPCDIR}/crypt.x
	${RPCGEN} -h -o ${.TARGET} ${RPCDIR}/crypt.x
