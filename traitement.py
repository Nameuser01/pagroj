#!/usr/bin/env python3

import sys
import os

f = open(".temp_file", "r")
tmp = f.readlines()
f.close()
os.system("rm .temp_file")

file_name = tmp[int(sys.argv[1]) - 1]
file_name = file_name[:-1]

file_reading = open(file_name, "r")
file_content = file_reading.readlines()
file_reading.close()

header = file_name[:10]
footer = file_name[17:]
new_name = header + "treated" + footer

file_writing = open(new_name, "a")
for line in file_content:
	if(line[0:5] == "https" or line[0:5] == "http:"):
		file_writing.write(line)
	else:
		pass

file_writing.close()
