/*-
 * Copyright (c) 2005-2006 The FreeBSD Project
 * All rights reserved.
 *
 * Author: Victor Cruceru <soc-victor@freebsd.org>
 *
 * Redistribution of this software and documentation and use in source and
 * binary forms, with or without modification, are permitted provided that
 * the following conditions are met:
 *
 * 1. Redistributions of source code or documentation must retain the above
 *    copyright notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Host Resources MIB implementation for SNMPd: instrumentation for
 * hrPrinterTable
 */

#include <sys/param.h>

#include <stdlib.h>

#include "hostres_snmp.h"

/* No printer backend is currently available. */
int
op_hrPrinterTable(struct snmp_context *ctx __unused,
    struct snmp_value *value __unused, u_int sub __unused,
    u_int iidx __unused, enum snmp_op curr_op)
{

	switch (curr_op) {
	case SNMP_OP_GETNEXT:
	case SNMP_OP_GET:
		return (SNMP_ERR_NOSUCHNAME);
	case SNMP_OP_SET:
		return (SNMP_ERR_NO_CREATION);
	case SNMP_OP_ROLLBACK:
	case SNMP_OP_COMMIT:
		abort();
	}
	abort();
}
