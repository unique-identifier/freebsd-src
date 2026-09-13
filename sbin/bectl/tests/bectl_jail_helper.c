/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2026 Charles Cowart
 */

#include <dirent.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

/* List the jail root without requiring a shell or shared libraries. */
static int
visible(const struct dirent *entry)
{
	return (entry->d_name[0] != '.');
}

int
main(void)
{
	struct dirent **entries;
	int count, i;

	count = scandir("/", &entries, visible, alphasort);
	if (count == -1)
		err(1, "scandir");
	for (i = 0; i < count; i++) {
		puts(entries[i]->d_name);
		free(entries[i]);
	}
	free(entries);
	return (ferror(stdout) ? 1 : 0);
}
