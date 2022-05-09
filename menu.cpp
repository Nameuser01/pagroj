#include <iostream>
#include <string>
// programme prévu pour les systèmes linux

using namespace std;

void menu();
void pressEnter();
void menu_installation();
int main()
{
	// déclaration des variables
	string navigation("*");

	system("clear");
	while( navigation != "0"
		|| navigation != "1"
		|| navigation != "2"
		|| navigation != "3"
		|| navigation != "4"
		|| navigation != "5"
		|| navigation != "a"
		|| navigation != "b"
		|| navigation != "c"
		|| navigation != "d")
	{
		// choix utilisateur
		menu();
		cout << "Quel est votre choix ?\n> " ;
		cin >> navigation ;
		cout << "\n" << endl;

		// fermer l'OUTIL de gestion de OUTIL
		if (navigation == "0")
		{
			cout << "Fin d'exécution du programme !" << endl;
			return 0;
		}
		// installation des fichiers et scripts nécessaires pour ce programme
		else if (navigation == "1") 
		{
			system("clear");
			bool poursuite(true);
			string bit_installation("*");
			while(poursuite == true)
			{
				// Choix utilisateur
				menu_installation();
				cout << "Que voulez vous faire ?\n> " ;
				cin >> bit_installation ;
				cout << "\n" << endl;

				// quitter l'OUTIL de gestion de OUTIL
				if (bit_installation == "0")
				{
					cout << "Fin d'exécution du programme !" << endl;
					return 0;
				}
				// fermer ce menu d'installation
				else if (bit_installation == "1")
				{
					cout << "Retour au menu précédent !" << endl;
					poursuite = false;
				}
				// installation de dos2unix
				else if (bit_installation == "a")
				{
					string user_rep("*");
					cout << "Êtes vous sûr de vouloir faire un <sudo apt install dos2unix> (O/n) ?\n> " ;
					cin >> user_rep ;
					if (user_rep == "Y" || user_rep == "y" || user_rep == "O" || user_rep == "o")
					{
						system("sudo apt install dos2unix");
					}
					else
					{
						cout << "Entrée incorrecte, dos2unix n'a pas été installé !" << endl;
					}
				}
				// téléchargement du script rep_check.sh" << endl;
				else if (bit_installation == "b")
				{
					string user_rep("*");
					cout << "Êtes vous sûr de vouloir faire un <curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/rep_check.sh> (O/n) ?\n> " ;
					cin >> user_rep ;
					if (user_rep == "Y" || user_rep == "y" || user_rep == "O" || user_rep == "o")
					{
						system("curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/rep_check.sh > .rep_check.sh");
						system("dos2unix .rep_check.sh");
						system("chmod +x .rep_check.sh");
					}
					else
					{
						cout << "Entrée incorrecte, rep_check.sh n'a pas été téléchargé !" << endl;
					}

				}
				// téléchargement du script loi_binomiale.py
				else if (bit_installation == "c")
				{
					string user_rep("*");
					cout << "Êtes vous sûr de vouloir faire un <curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/loi_binomiale.py> (O/n) ?\n> " ;
					cin >> user_rep ;
					if (user_rep == "Y" || user_rep == "y" || user_rep == "O" || user_rep == "o")
					{
						system("curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/loi_binomiale.py > .loi_binomiale.py");
						system("dos2unix .loi_binomiale.py");
						system("chmod +x .loi_binomiale.py");
					}
					else
					{
						cout << "Entrée incorrecte, loi_binomiale.py n'a pas été téléchargé !" << endl;
					}

				}
				else
				{
					cout << "Entrée incorrecte, réessayez !" << endl;
				}
				cout << "\n" << endl;
				// !! filtrage du press enter !!
				pressEnter();
			}
		}
		// visualisation des répertoires de OUTIL
		else if (navigation == "2")
		{
			system("ls -Rl .");
		}
		// visualisation du répertoire de sortie de OUTIL
		else if (navigation == "3")
		{
			system("./.rep_check.sh");
			system("ls -l db/");
		}
		// visualisation des fichiers de sortie bruts de OUTIL
		else if (navigation == "4")
		{
			system("./.rep_check.sh");
			system("ls -l db/OUTIL_results_????????_??????.txt");
		}
		// visualisation des fichiers de sortis triés de OUTIL
		else if (navigation == "5")
		{
			system("./.rep_check.sh");
			system("ls -l db/OUTIL_treated_????????_??????.txt");
		}
		// visualisation de la répartition du random en python
		else if (navigation == "6")
		{
			int arg_min(0), arg_max(0), arg_tirages(0), indicateur(0);
			bool stayHere(true);
			// choix des arguments pour .loi_binomiale.py
			while(stayHere == true)
			{
				// choix utilisateur
				cout << "Quelle est la borne min pour la fenêtre de random à tester ?\n> " ;
				cin >> arg_min ;
				cout << "\nQuelle est la borne max pour la fenêtre de random à tester ?\n> " ;
				cin >> arg_max ;
				cout << "\nCombien de tirages sont a effectuer ?\n> " ;
				cin >> arg_tirages ;
				if (arg_max <= arg_min || arg_min <= 0 || arg_tirages <= 0)
				{
					cout << "Entrée incorrecte, réessayez !" << endl;
				}
				else
				{
					cout << "Lancement du script ..." << endl;
					stayHere = false;
				}
			}
			string commande("./.loi_binomiale.py " + to_string(arg_min) + " " + to_string(arg_max) + " " + to_string(arg_tirages) + "&");
			system((commande).c_str());
		}
		// réorganisation du répertoire OUTIL
		else if (navigation == "a")
		{
			system("./.rep_check.sh");
			system("mv -v OUTIL_???????_????????_??????.txt db/");
		}
		// traiter les fichiers de sortie de OUTIL
		else if (navigation == "b")
		{
			// présentation utilisateur
			cout << "Fichiers bruts : \n" << endl;
			system("ls db/OUTIL_results_????????_??????.txt > .temp_file");
			system("cat -n .temp_file");
			cout << "\n\nFichiers traités :\n" << endl;
			system("ls db/OUTIL_treated_????????_??????.txt");

			//choix utilisateur
			int choix_fichier(0);
			cout << "\n\nQuel fichier voulez vous traiter (n° de fichier) ?\n> " ;
			cin >> choix_fichier ;
			cout << "\n" << endl;

			// process
			string commande("./.traitement.py " + to_string(choix_fichier) + "&");
			cout << "Lancement en cours ..." << endl;
			system((commande).c_str());
			cout << "\nTraitement effectué !\n\n" << endl;
		}
		// analyse statistique d'un fichier (GUI)
		else if (navigation == "c")
		{
			// choix utilisateur
			int choix_fichier(0), accuracy(0);
			system("ls db/OUTIL_treated_????????_??????.txt > .temp_file");
			system("cat -n .temp_file");
			cout << "\nSur quel fichier souhaitez vous travailler (n° de fichier) ?\n> " ;
			cin >> choix_fichier ;
			cout << "\nÀ combien d'occurences voulez vous limiter le résultat graphique ?\n> " ;
			cin >> accuracy ;
			cout << "\n" << endl;

			// process
			string commande("./.stat.py " + to_string(choix_fichier) + " " + to_string(accuracy) + "&");
			cout << "Lancement en cours ..." << endl;
			system((commande).c_str());
		}
		// exploration des résultats
		else if (navigation == "d")
		{
			// affichage des propositions
			cout << "Liste des fichiers disponibles :\n" << endl;
			system("ls db/OUTIL_treated_????????_??????.txt > .temp_file");
			system("cat -n .temp_file");

			// choix utilisateur
			int choix_fichier(0);
			cout << "\n\nQuel fichier voulez vous explorer ?\n> " ;
			cin >> choix_fichier ;
			string commande("./.voyager.sh " + to_string(choix_fichier) + "&");
			cout << "Lancement en cours ..." << endl;
			system((commande).c_str());
		}
		else
		{
			cout << "Entrée incorrecte, réessayez !" << endl;
		}
		// !! filtrage du press enter !!
		pressEnter();
	}
	cout << "Fin d'exécution du programme !" << endl;
	return 0;
}

// afficher le menu de sélection pour l'utilisateur
void menu()
{
	cout << "########## Menu de sélection ##########\n" << endl;
	cout << "0 - fermer le programme" << endl;
	cout << "1 - installation requirements pour ce programme" << endl;
	cout << "2 - visualisation des répertoires de OUTIL" << endl;
	cout << "3 - visualisation du répertoire de sortie de OUTIL" << endl;
	cout << "4 - visualisation des fichiers de sortie bruts de OUTIL" << endl;
	cout << "5 - visualisation des fichiers de sortis triés de OUTIL" << endl;
	cout << "6 - visualisation de la répartition du random en python" << endl;
	cout << "a + réorganisation du répertoire OUTIL" << endl;
	cout << "b + traiter les fichiers de sortie de OUTIL" << endl;
	cout << "c + analyse statistique d'un fichier" << endl;
	cout << "d + exploration des résultats" << endl;
	cout << "\n" << endl;
}

// pause avant de poursuivre l'exécution
void pressEnter()
{
	cout << "\nAppuyez sur entrée pour continuer..." << endl;
	cin.get();
	cin.get();
	system("clear");
}

// menu d'installation des requirements
void menu_installation()
{
	cout << "~~~~~~~~~~ Menu de sélection ~~~~~~~~~~\n" << endl;
	cout << "0 - fermer le programme" << endl;
	cout << "1 - quitter ce menu d'installation" << endl;
	cout << "a + installation de dos2unix (pour le bon fonctionnement des scripts récupérés depuis github)" << endl;
	cout << "b + téléchargement du script rep_check.sh" << endl;
	cout << "c + téléchargement du script loi_binomiale.py" << endl;
	cout << "d + téléchargement du script traitement.py" << endl;
	cout <<" e + téléchargement du script !!!!!!!!!!!.sh" << endl;
	cout << "\n" << endl;
}
