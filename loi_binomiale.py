#!/usr/bin/env python3

from collections import Counter
from random import randint as rd
import matplotlib.pyplot as plt
import numpy as np

# User variables
random_range = 1000000
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
	db_sorted = sorted(db_compte.items())
	return db_sorted

def trace_graphique(elements_compte, random_range):
	x = []
	y = []
	x, y = zip(*elements_compte)  # untupling

	plt.grid(True)
	plt.xlabel("Valeur de x")
	plt.ylabel("Occurence pour x")
	plt.plot(x, y)
	plt.title(f"Visualisation de la répartition des valeurs lors d'un\ntirage pseudo-aléatoire avec la librairie \"random\"\npour {random_range} d'évènements.")
	plt.show()

# Control
echantillon_brut = []
echantillon_brut = random_generation(min_range, max_range, random_range)
elements_compte = []
elements_compte = compteur(echantillon_brut)
trace_graphique(elements_compte, random_range)
