#!/bin/bash

file_name=`head -"$1" .temp_file | tail -1`
for i in `cat $file_name` ;
do
	firefox $i --new-tab &
done
rm .temp_file
