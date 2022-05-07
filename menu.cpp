#include <iostream>
#include <string>

using namespace std;

void menu();
void pressEnter();
void sh_do_rep_exists();
int main()
{
	// Déclaration des variables
	string navigation("*");

	while(navigation != "0"
		|| navigation != "1"
		|| navigation != "2"
		|| navigation != "3"
		|| navigation != "4"
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
		if(navigation == "0")
		{
			cout << "Fin d'exécution du programme !" << endl;
			return 0;
		}
		// visualisation des répertoires de OUTIL
		else if (navigation == "1") 
		{
			system("ls -Rl .");
		}
		// visualisation du répertoire de sortie de OUTIL
		else if (navigation == "2")
		{
			sh_do_rep_exists();
			system("ls -l db/");
		}
		// visualisation des fichiers de sortie bruts de OUTIL
		else if (navigation == "3")
		{
			sh_do_rep_exists();
			system("ls -l db/OUTIL_????????_??????.txt");
		}
		else if (navigation == "4")
		{
			sh_do_rep_exists();
			system("ls -l db/OUTIL_????????_??????_treated.txt");
		}
		else if (navigation == "a")
		{
			continue;
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
		cout << "\nAppuyez sur entrée pour continuer..."; 
		pressEnter();
		system("clear");
	}
	
	return 0;
}

void menu()
{
	cout << "########## Menu de sélection ##########\n" << endl;
	cout << "0 - fermer le programme" << endl;
	cout << "1 - visualisation des répertoires de OUTIL" << endl;
	cout << "2 - visualisation du répertoire de sortie de OUTIL" << endl;
	cout << "3 - visualisation des fichiers de sortie bruts de OUTIL" << endl;
	cout << "4 - visualisation des fichiers de sortis triés de OUTIL" << endl;
	cout << "a + réorganisation du répertoire OUTIL" << endl;
	cout << "b + analyse statistique d'un fichier (GUI)" << endl;
	cout << "c + analyse statistique d'un fichier (SHELL)" << endl;
	cout << "d + exploration des résultats" << endl;
	cout << "\n" << endl;
}

void pressEnter()
{
	cin.get();
	cin.get();
}

void sh_do_rep_exists()
{
	system("echo '#!/bin/bash' > .check_rep.sh");
	system("echo 'if [[ -d \"db\" ]]' >> .check_rep.sh");
	system("echo 'then' >> .check_rep.sh");
	system("echo \"echo 'File exists on your computer'\" >> .check_rep.sh");
	system("echo 'else' >> .check_rep.sh");
	system("echo 'mkdir db' >> .check_rep.sh");
	system("echo \"echo 'Le fichier n\'existait pas, il vient d\'être créé !'\" >> .check_rep.sh");
	system("echo 'fi' >> .check_rep.sh");
	system("chmod +x .check_rep.sh");
	system("./.check_rep.sh");
}