#!/bin/bash
# scrape news bash script
# 319046504 laviel@campus.technion.ac.il lavie lederman
# 206159527 shahary@campus.technion.ac.il shahar yankelovich
# set working params
URL="https://www.ynetnews.com/category/3082"
data=$(wget --no-check-certificate -O - $URL 2>/dev/null)

articles=$(echo "$data" | 
			grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort | uniq |

while IFS= read -r line; do
wget --no-check-certificate -O - $line 2>/dev/null |
echo "$line, Netanyahu, " #" $(grep -o "Netanyahu" | wc -l)"
done
) #nope
