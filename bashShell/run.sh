#!/bin/bash

#--------> Print name and date  <-------------
echo "Wellcome Asraf Ali"
echo "Today is - " `date`

#-----> Checking cmd line arg <--------
if [[ $# -eq 0 ]]; then
	echo -e "No Source file is Provided"
	echo -e "commad should looks like : bash run.sh source.cpp"
	exit 0
fi

#----------> Store the name of source code in $1 and compile it
nameProg=$1
output=$(g++ -std=c++2a $nameProg 2>&1)
if [[ $? -ne 0 ]];then
	#there is an error, show error in $output
	echo -e "Error ---> \n$output"
else
	#compilation successfull
	./a.out
	echo -e "\n"
fi

