#include <iostream>
#include <string>
// Programme prévu pour les systèmes linux exclusivement

using namespace std;

void menu();
void pressEnter();
void sh_do_rep_exists();
void sh_rep_cleaning();
void menu_installation();
int main()
{
	// Déclaration des variables
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
		// Sélection utilisateur
		menu();
		cout << "Quel est votre choix ?\n> " ;
		cin >> navigation ;
		cout << "\n" << endl;

		// Fermer l'outil de gestion de OUTIL
		if (navigation == "0")
		{
			cout << "Fin d'exécution du programme !" << endl;
			return 0;
		}
		// Installation des fichiers et scripts nécessaires pour ce programme
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

				// fermer l'outil de gestion de OUTIL
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
				//téléchargement du script rep_check.sh" << endl;
				else if (bit_installation == "b")
				{
					string user_rep("*");
					cout << "Êtes vous sûr de vouloir faire un <curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/rep_check.sh> (O/n) ?\n> " ;
					cin >> user_rep ;
					if (user_rep == "Y" || user_rep == "y" || user_rep == "O" || user_rep == "o")
					{
						system("curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/rep_check.sh > .rep_check.sh");
					}
					else
					{
						cout << "Entrée incorrecte, rep_check.sh n'a pas été téléchargé !" << endl;
					}

				}
				//téléchargement du script loi_binomiale.py
				else if (bit_installation == "c")
				{
					string user_rep("*");
					cout << "Êtes vous sûr de vouloir faire un <curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/loi_binomiale.py> (O/n) ?\n> " ;
					cin >> user_rep ;
					if (user_rep == "Y" || user_rep == "y" || user_rep == "O" || user_rep == "o")
					{
						system("curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/loi_binomiale.py > .loi_binomiale.py");
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
			sh_do_rep_exists();
			system("ls -l db/");
		}
		// visualisation des fichiers de sortie bruts de OUTIL
		else if (navigation == "4")
		{
			sh_do_rep_exists();
			system("ls -l db/OUTIL_results_????????_??????.txt");
		}
		// visualisation des fichiers de sortis triés de OUTIL
		else if (navigation == "5")
		{
			sh_do_rep_exists();
			system("ls -l db/OUTIL_treated_????????_??????.txt");
		}
		// visualisation de la répartition du random en python
		else if (navigation == "6")
		{
			continue;
		}
		// réorganisation du répertoire OUTIL
		else if (navigation == "a")
		{
			sh_do_rep_exists();
			// system(("cat "+foo).c_str());
		}
		else if (navigation == "b")
		{
			continue;
		}
		else if (navigation == "c")
		{
			continue;
		}
		else if (navigation == "d")
		{
			continue;
		}
		else
		{
			cout << "Entrée incorrecte, réessayez !" << endl;
		} 
		pressEnter();
	}
	cout << "Fin d'exécution du programme !" << endl;
	return 0;
}

// Afficher le menu de sélection pour l'utilisateur
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

// Pause avant de poursuivre l'exécution
void pressEnter()
{
	cout << "\nAppuyez sur entrée pour continuer..." << endl;
	cin.get();
	cin.get();
	system("clear");
}

// Récupérer et exécuter un script de vérification de l'existence d'un fichier, sur github
void sh_do_rep_exists()
{
	system("curl https://raw.githubusercontent.com/Nameuser01/pagroj/master/rep_check.sh > .rep_check.sh");
	system("chmod +x .rep_check.sh");
	system("dos2unix .rep_check.sh");
	system("./.rep_check.sh");
}

// Trie des fichiers de sortie vers le répertoire approprié
void sh_rep_cleaning()
{
	// system("mv -vi"); // virer tous les fichiers OUTIL dans le rep db
}

// Menu d'installation des requirements
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
