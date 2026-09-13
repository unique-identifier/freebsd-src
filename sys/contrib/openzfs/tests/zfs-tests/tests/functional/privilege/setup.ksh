#!/bin/ksh -p
# SPDX-License-Identifier: CDDL-1.0
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or https://opensource.org/licenses/CDDL-1.0.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#

#
# Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#

#
# Copyright (c) 2013, 2016 by Delphix. All rights reserved.
#

. $STF_SUITE/include/libtest.shlib

ZFS_USER=zfsrbac



# create a unique user that we can use to run the tests,
# making sure not to clobber any existing users.
FOUND=""
while [ -z "${FOUND}" ]
do
  USER_EXISTS=$( grep $ZFS_USER /etc/passwd )
  if [ ! -z "${USER_EXISTS}" ]
  then
      ZFS_USER="${ZFS_USER}x"
  else
      FOUND="true"
  fi
done

log_must mkdir -p /export/home/$ZFS_USER
log_must useradd -c "ZFS Privileges Test User" -d /export/home/$ZFS_USER $ZFS_USER

echo $ZFS_USER > $TEST_BASE_DIR/zfs-privs-test-user.txt

log_pass
