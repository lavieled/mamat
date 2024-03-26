#!/bin/bash

#Cleaning the rules file from unnecesery elements.
clean_rule_file=$(cat $1 | sed '/^$/d' 
                  | sed 's/#.*//' | sed 's/ //g')

#We create an array to which we will add the relevant packets.
rel_packets=()

#We keep the input in a variable.
packets=($cat);

#Add a loop that checks if a rule is taken

#Sort and uniq the final array
