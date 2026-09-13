
# avoid duplication
DIRDEPS.AUDIT.yes= lib/libbsm
DIRDEPS.BLACKLIST_SUPPORT.yes+= lib/libblacklist
DIRDEPS.BLOCKLIST_SUPPORT.yes+= lib/libblocklist
DIRDEPS.CASPER.yes+= lib/libcasper/libcasper
DIRDEPS.JAIL.yes+= lib/libjail
DIRDEPS.NIS.yes+= \
	include/rpc \
	include/rpcsvc \
	lib/librpcsvc

DIRDEPS.OPENSSL.yes+= secure/lib/libcrypto
DIRDEPS.OPENSSL.no+= lib/libmd
DIRDEPS.PAM_SUPPORT.yes+= lib/libpam/libpam
DIRDEPS.TCP_WRAPPERS.yes+= lib/libwrap

MK_FDT.${DEP_MACHINE} ?= yes

.-include <site.dirdeps-options.mk>
