#!/bin/bash
# scrape news bash script
# 319046504 laviel@campus.technion.ac.il lavie lederman
# 206159527 shahary@campus.technion.ac.il shahar yankelovich
URL="https://www.ynetnews.com/category/3082" # site to scan
data=$(wget --no-check-certificate -O - $URL 2>/dev/null)

articles=$(echo "$data" | 
	grep -oP "https://(www.)?ynetnews.com/article/[0-9a-zA-Z]+" | sort | uniq)
#choose all relevant links, sort and delete duplicates 
while IFS= read -r line; do
article_data=$(wget --no-check-certificate -O - $line 2>/dev/null)
bibi=$(echo "$article_data" | grep -o "Netanyahu" | wc -l)
gantz=$(echo "$article_data" | grep -o "Gantz" | wc -l)
#for each links, go to article and count num appearces of chosen politicians
if [[ ("$bibi" -eq 0) && ("$gantz" -eq 0) ]]; then
	echo "$line, -"
else 
echo "$line, Netanyahu, $bibi, Gantz, $gantz"
fi
#print to screen results
done <<< "$articles"
