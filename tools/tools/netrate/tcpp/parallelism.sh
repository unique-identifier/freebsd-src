#!/bin/sh
#
#
# Run tcpp -s -p 8 on the server, then this on the client.
#
# Note awkwardly hard-coded IP address below.
#
# Accepts two arguments: [filename] [csvprefix]
#

totalbytes=4800000		# Bytes per connection
cores=8
trials=6
ptcps=24			# Max TCPs concurrently
ntcps=240			# Total TCPs over test
nips=4			# Number of local IP addresses to use
baseip=192.168.100.200	# First IP address to use

for core in $(jot "$cores"); do
  for trial in $(jot "$trials"); do
    mflag=$((ptcps / core))
    tflag=$((ntcps / core))
    printf '%s,%s,%s,' "$2" "$core" "$trial" >> "$1"
    ./tcpp -c 192.168.100.102 -p $core -b $totalbytes -m $mflag \
      -t $tflag -M $nips -l $baseip >> "$1"
  done
done
