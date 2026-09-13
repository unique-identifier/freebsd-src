# Compatibility include for Makefiles that still declare manual pages.
# Manual-page generation, installation, and linting are no longer supported.

all-man maninstall realmaninstall manlinksinstall manlint checkmanlinks: .PHONY .NOTMAIN
