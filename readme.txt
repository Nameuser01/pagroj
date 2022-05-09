Projet de développement d'outils / scripts autour d’un logiciel existant.

Utilisation :
Ne pas cloner le projet github, entrer les commandes suivantes ;
- curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/menu.cpp > menu.cpp
- g++ menu.cpp -o menu
- rm menu.cpp
- ./menu

Lors de l'exécution du fichier menu effectuer les actions suivantes :
- Accéder au menu d'installation "1"
- Installer dos2unix "a"
- Télécharger les scripts avec "b", "c", "d", "e" et "f"

Fonction des fichiers du répo :
- menu.cpp => menu de gestion de tous les autres scripts (installation, lancement etc...)
- loi_binomiale.py => visualiser graphiquement la répartition des valeurs d'un tirage random avec la librairie random (python)
- output.png => exemple de résultat proposé par le fichier loi_binomiale.py
- rep_check.sh => script de vérification de l'existence d'un répertoire, sinon, création de celui-ci.
- traitement.py => parser permettant de rendre les fichiers de sortie, exploitables par les autres scripts
- stat.py => compte le nombre d'occurence par nom de domaine dans les fichiers qu'il traite. Affiche le résultat sous forme graphique
- voyager.sh => récupère puis cherche chaque ligne d'un fichier, dans firefox
