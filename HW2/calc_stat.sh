# enter the bash code
#!bin/bash
# First we check the input's validity
if [[ ! "$1" =~ ^[0-9]$ || ! $# -eq 1 ]] {
  #Input invalid
  error="Wrong number of arguments";
  error>2;
  exit(1);
}
