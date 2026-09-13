#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Filter explicit obsolete paths without following manual-directory symlinks.
# The leaf itself may be a symlink: retired page aliases must still be removed.

set -eu

destdir=${1:-/}
last_parent=
parent_is_safe=yes
while IFS= read -r path; do
	case "$path" in
	usr/share/man|usr/share/man/*|usr/share/openssl/man|usr/share/openssl/man/*)
		parent=${path%/*}
		if [ "$parent" != "$last_parent" ]; then
			last_parent=$parent
			parent_is_safe=yes
			while [ "$parent" != . ]; do
				if [ -L "$destdir/$parent" ]; then
					parent_is_safe=no
					break
				fi
				case "$parent" in
				*/*) parent=${parent%/*} ;;
				*) parent=. ;;
				esac
			done
		fi
		[ "$parent_is_safe" = yes ] || continue
		;;
	esac
	printf '%s\n' "$path"
done
