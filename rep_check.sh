#!/bin/bash
if [[ -d "db" ]]
then
	echo ""
else
	mkdir db
	echo "Le repertoire vient d'être créé !"
fi
