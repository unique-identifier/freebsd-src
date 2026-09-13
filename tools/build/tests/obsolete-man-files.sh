#!/bin/sh
# SPDX-License-Identifier: BSD-2-Clause
# Run with: sh tools/build/tests/obsolete-man-files.sh

set -eu
filter=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)/filter-obsolete-manpaths.sh
work=$(mktemp -d "${TMPDIR:-/tmp}/obsolete-man-files.XXXXXX")
trap 'rm -rf "$work"' EXIT HUP INT TERM
root="$work/destination with spaces"
mkdir -p "$root/usr/share/man/man1" "$root/usr/local/share/man/man1"

cat > "$work/paths" <<'EOF'
usr/bin/man
usr/share/man
usr/share/man/man1
usr/share/man/man1/cat.1
usr/share/man/man1/cat.1.gz
EOF
sh "$filter" "$root" < "$work/paths" > "$work/result"
cmp "$work/paths" "$work/result"

# A dangling leaf alias remains eligible for removal.
ln -s missing "$root/usr/share/man/man1/cat.1.gz"
sh "$filter" "$root" < "$work/paths" > "$work/result"
cmp "$work/paths" "$work/result"

# A linked section is retained as a directory entry, but never traversed.
mv "$root/usr/share/man/man1" "$root/saved-section"
ln -s ../../local/share/man/man1 "$root/usr/share/man/man1"
head -n 3 "$work/paths" > "$work/expected"
sh "$filter" "$root" < "$work/paths" > "$work/result"
cmp "$work/expected" "$work/result"

# A linked manual root also blocks all child paths.
mv "$root/usr/share/man" "$root/saved-root"
ln -s ../local/share/man "$root/usr/share/man"
head -n 2 "$work/paths" > "$work/expected"
sh "$filter" "$root" < "$work/paths" > "$work/result"
cmp "$work/expected" "$work/result"

# Even a link above the manual root must not be followed.
mv "$root/usr/share" "$root/saved-share"
ln -s local/share "$root/usr/share"
head -n 1 "$work/paths" > "$work/expected"
sh "$filter" "$root" < "$work/paths" > "$work/result"
cmp "$work/expected" "$work/result"

# Listing candidates never requires the destination tree to exist.
sh "$filter" "$work/absent" < "$work/paths" > "$work/result"
cmp "$work/paths" "$work/result"
printf '%s\n' 'Obsolete manual-path filtering passed.'
