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

		// fermer l'outil de gestion de OUTIL
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

				// quitter l'outil de gestion de OUTIL
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
			int arg_min(0), arg_max(0), arg_tirages(0);
			// choix des arguments pour .loi_binomiale.py
			while(arg_max <= arg_min || arg_min <= 0 || arg_tirages <= 0)
			{
				// choix utilisateur
				cout << "Quelle est la borne min pour la fenêtre de random à tester ?\n> " ;
				cin >> arg_min ;
				cout << "\nQuelle est la borne max pour la fenêtre de random à tester ?\n> " ;
				cin >> arg_max ;
				cout << "\nCombien de tirages sont a effectuer ?\n> " ;
				cin >> arg_tirages ;
			}
			string commande("./.loi_binomiale.py " + to_string(arg_min) + " " + to_string(arg_max) + " " + to_string(arg_tirages));
			system((commande).c_str());
		}
		// réorganisation du répertoire OUTIL
		else if (navigation == "a")
		{
			system("./.rep_check.sh");
			system("mv -iv OUTIL_???????_????????_??????.txt db/");
		}
		// analyse statistique d'un fichier (GUI)
		else if (navigation == "b")
		{
			continue;
		}
		// analyse statistique d'un fichier (SHELL)
		else if (navigation == "c")
		{
			continue;
		}
		// exploration des résultats
		else if (navigation == "d")
		{
			continue;
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
	cout << "b + analyse statistique d'un fichier (GUI)" << endl;
	cout << "c + analyse statistique d'un fichier (SHELL)" << endl;
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
	cout << "\n" << endl;
}
