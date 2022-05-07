#!/bin/bash
if [[ -d "db" ]]
then
	echo "Le repertoire existe déjà !"
else
	mkdir db
	echo "Le repertoire n'existait pas, il vient d'être créé !"
fi
