#!/usr/bin/env python3

from collections import Counter
from random import randint as rd
import matplotlib.pyplot as plt

# User variables
random_range = 10
min_range = 50
max_range = 120

# Process
def random_generation(min, max, random_range):
	stockage = []
	borne_inf = 0
	while (borne_inf < random_range):
		borne_inf += 1
		stockage.append(rd(min, max))
	return stockage

def compteur(echantillon):
	db_compte = Counter()
	for element in echantillon:
		db_compte[element] += 1
	# Sorting the db_compte database before returning
	print(db_compte)
	db_sorted = sorted(db_compte.items())
	return db_sorted

def trace_graphique():
	# On trace le graphique en espérant avoir une loi binomiale qui se dessine plus ou moins
	pass

# Control
echantillon_brut = []
echantillon_brut = random_generation(min_range, max_range, random_range)
elements_compte = []
elements_compte = compteur(echantillon_brut)
print(elements_compte)
