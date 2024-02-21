# enter the bash code
#!bin/bash
# First we check the input's validity - that it is a course number with 6 digits
if [[ ! "$1" =~ ^[0-9]$ || ! $# -eq 1 ]]; then
  #Invalid input
  error="Wrong number of arguments";
  error>$2;
  exit(1);
fi
# Second, we check if there is a valid file inside the repo
if [[ ]]; then
  #There is no such file
  error="Course not found";
  error>$2;
  exit(1);
fi
# Third, we check if a repository with the wanted name already exists
if [[ ]]; then
# There is a repo already, deleting it
  rm -rf ""
fi
# Creating the new repository
dir="$1_stat"
# Reading the data from the recently created file 
# and produce a histogram into a file

# Creating a file that combines all the statistics:
# Avg, Median, Min, max - devided by a tab
