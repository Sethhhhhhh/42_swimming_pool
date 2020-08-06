#!/bin/sh
cat /etc/passwd | grep -v "#" | awk '!(NR%2)' | cut -d ':' -f1 | rev | sort -r | awk '(NR >= '$FT_LINE1' && NR <= '$FT_LINE2')' | sed 's/$/, /g' | tr -d "\n" | sed 's/, $/./g' | tr -d '\n'
