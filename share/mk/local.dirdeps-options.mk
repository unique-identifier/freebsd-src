
# avoid duplication
DIRDEPS.AUDIT.yes= lib/libbsm
DIRDEPS.BLACKLIST_SUPPORT.yes+= lib/libblacklist
DIRDEPS.BLOCKLIST_SUPPORT.yes+= lib/libblocklist
DIRDEPS.CASPER.yes+= lib/libcasper/libcasper
DIRDEPS.JAIL.yes+= lib/libjail
DIRDEPS.KERBEROS_SUPPORT.yes+= \
	krb5/lib/gssapi \
	krb5/lib/krb5 \
	krb5/lib/crypto \
	krb5/util/et \
	krb5/util/support

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
