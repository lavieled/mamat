#319046504 laviel@campus.technion.ac.il lavie lederman
#206159527 shahary@campus.technion.ac.il shahar yankelovich

#!/bin/bash
  res_dir="$1_stat"
# We recreate the directory empty
  rm -rf "$res_dir"; mkdir "$res_dir"
 #create the files we will pass the stats to
  touch "$1_stat"/histogram.txt
  touch "$1_stat"/statistics.txt
# First we check the input's validity - that it is a course number with 6 digits
if [[ ! "$1" =~ ^[0-9]{6}$ || ! "$#" -eq 1 ]]; then
  #Invalid input
  echo "Wrong number of arguments" >&2
  exit 1
# Second, we check if there is a valid grades text file inside the repo
elif [[ ! -e "$1.txt" ]]; then
  #There is no such file
  echo "Course not found" >&2
  exit 1
else
# We create a new file with the statistics
 #create the files we will pass the stats to
# Then, read the data from the input/file 
# And produce a histogram into a file

# Compiling the histogram code
  #gcc -g -Wall "hist.c" -o "hist.exe" 
  ./hist.exe -nbins 10 < "$1.txt" > "histogram.txt"
  # rm "histogram.exe"
# Creating a file that combines all the statistics:
# Avg, Median, Min, max - devided by a tab
#calculate course statistics
  #create array of files to compile and run for the statistics
  #source_files=("mean.exe" "median.exe" "min.exe" "max.exe")
  #loop to run and add the stats each program
  for file in ("mean.exe" "median.exe" "min.exe" "max.exe"); do
  #get function from array
  #func_name=$(basename "$file")
  #compile the current function
  #gcc -g -Wall -o "${func_name}" "$file"
  #run the func and direct output to statistics file
  ./"${file}" < "$1.txt" >> "statistics.txt" #2>&1
  #rm "${func_name}"
  done
  #mv "statistics.txt" "${course_num}_stat"
  #mv "histogram.txt" "${course_num}_stat"
fi
