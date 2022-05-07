#include <iostream>
#include <string>

using namespace std;

void menu();
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
		if(navigation == "0")
		{
			cout << "Fin d'exécution du programme !" << endl;
			return 0;
		}
	}

	menu();
	// system("");
	return 0;
}

void menu()
{
	cout << "########## Menu de sélection ##########\n" << endl;
	cout << "0 - fermer le programme" << endl;
	cout << "1 - visualisation des répertoires de OUTIL" << endl;
	cout << "2 - visualisation du répertoire de sortie de OUTIL" << endl;
	cout << "3 - visualisation des fichiers de sortie bruts de OUTIL" << endl;
	cout << "4 - visualisation des fichiers de sortie triés de OUTIL" << endl;
	cout << "a + réorganisation du répertoire OUTIL" << endl;
	cout << "b + analyse statistique d'un fichier (GUI)" << endl;
	cout << "c + analyse statistique d'un fichier (SHELL)" << endl;
	cout << "d + exploration des résultats" << endl;
}
