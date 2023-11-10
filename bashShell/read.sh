#!/bin/bash

#------> Read the file from log.txt <-------
while read line
do
	echo $line
done < log.txt
