# enter the bash code
#!bin/bash
# First we check the input's validity - that it is a course number with 6 digits
if [[ ! "$1" =~ ^[0-9]$ || ! $# -eq 1 ]]; then
  #Invalid input
  error="Wrong number of arguments";
  error>$2;
  exit(1);
# Second, we check if there is a valid grades text file inside the repo
elif [[ ! -e "$1.txt" ]]; then
  #There is no such file
  error="Course not found";
  error>$2;
  exit(1);
else
# We create a new file with the statistics
# And read the data from the input/file 
# and produce a histogram into a file
  res_dir="$1_stat"
  grades_file="$1_stat/grades.txt"
  course_statistics="$1_stat/statistics.txt"
# We recreate the directory empty
  rm -rf "$res_dir"; mkdir "$res_dir"
  
# Creating a file that combines all the statistics:
# Avg, Median, Min, max - devided by a tab
fi
