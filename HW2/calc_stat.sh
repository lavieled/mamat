#!/bin/bash
# First we check the input's validity - that it is a course number with 6 digits
# And that it contains more than one line
if [[ ! "$1" =~ ^[0-9]{6}$ || ! $# -eq 1 ]]; then
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
# Then, read the data from the input/file 
# And produce a histogram into a file
  res_dir="$1_stat"
# We recreate the directory empty
  rm -rf "$res_dir"; mkdir "$res_dir"
#************************************ Maybe not necessery grades_file="$1_stat/grades.txt"
#********************************************** course_statistics="$1_stat/statistics.txt"
# Compiling the histogram code
  gcc -g -Wall -o "histogram.exe" "histogram.c"
  ./histogram.exe "histogram.txt" "$1_stat/grades.txt"
# Creating a file that combines all the statistics:
# Avg, Median, Min, max - devided by a tab
#calculate course statistics
  #init statistics file
  course_statistics="$1_stat/statistics.txt"
  #create array of files to compile and run for the statistics
  source_files=("mean.c" "median.c" "min.c" "max.c")
  #loop to run and add the stats each program
  for file in "${source_files[@]}"; do
  #get function from array
  func_name=$(basename "$file" .c)
  #compile the current function
  gcc -o "$func_name" "$file"
  #run the func and direct output to statistics file
  ./"$func_name" >> "$course_statistics"
  rm "$func_name"
  done
fi
