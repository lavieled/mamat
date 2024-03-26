#!/bin/bash

if [ ! "$#" -eq 1 ]; then
  #Invalid input
  echo "Wrong number of arguments" >&2
  exit 1
fi
course_num=$1
course_file="${course_num}"
# we check if there is a valid grades text file
if [ ! -f "${course_file}" ]; then
  #There is no such file
  echo "Course not found" >&2
  exit 1
fi
course_folder="${course_num}_stat"
if [ -d "$course_folder" ]; then
    rm -rf "$course_folder"
fi
mkdir "$course_folder"
# Then, read the data from the input/file
# And produce a histogram into a file
  hist_out="${course_folder}/histogram.txt"
  ./hist.exe "./$course_file" > "$hist_out"
 
  #calculate statistics
  avg=$(./mean.exe "$course_file")
  median=$(./median.exe "$course_file")
  min=$(./min.exe "$course_file")
  max=$(./max.exe "$course_file")
 
  #create statistics file
  stats_file="${course_folder}/statistics.txt"
 
  #write statistics to file
  echo "${avg}${median}${min}${max}" > "$stats_file"
