#!/bin/bash

#-------> While loop <---------------
i=1
while [[ $i -le 9 ]]; 
do
	echo -e "While loop -> $i"
	((i++))
done

#---------> For loop <---------------- 
for i in {1..9}
do
	echo -e "For loop -> $i"
done
