#!/usr/bin/env python3

import matplotlib.pyplot as plt
from collections import Counter
import random
import string
import sys
import re
import os

# Control
ACCURACY = int(sys.argv[2])

f = open(".temp_file", "r")
tmp = f.readlines()
f.close()
os.system("rm .temp_file")

argument = tmp[int(sys.argv[1]) - 1]
argument = argument[:-1]
file_reading = open(argument, "r")
file_content = file_reading.readlines()
file_reading.close()

liens = []
for line in file_content:
	if(line[0:5] == "https"):
		next_stop = line.find('/', 9)
		liens.append(line[8:next_stop])
	elif(line[0:5] == "http:"):
		next_stop = line.find('/', 8)
		liens.append(line[7:next_stop])
	else:
		pass

cnt = Counter()
for domaine in liens:
	cnt[domaine] += 1

# Récupération des éléments qui se répètent le plus
domain_name = []
domain_rep = []
for k, v in sorted(cnt.items(), key=lambda item: item[1]):
	if (v >= ACCURACY):
		domain_name.append(k)
		domain_rep.append(v)
	else:
		pass

plt.barh(domain_name, domain_rep)
plt.ylabel("Nombre d'occurences")
plt.show()
