/*
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<sstream>
#include<vector>
using namespace std;




string GetNomFichier()
{
	srand(time(0));
	int aleatoire = rand() % 9 + 4;
	string nombre = to_string(aleatoire);
	return "C:\\temp\\FICHIERS\\FICHIERS\\mots_" + nombre + ".txt";
}
int GetNombreLigne(string nom_fic)
{
	int n_ligne = 0;
	ifstream fichier(nom_fic);
	if (fichier)
	{
		string ligne;
		while (getline(fichier, ligne))
		{
			n_ligne++ ; 
		}
	}
	return n_ligne;
}

string GetMot(string nom_fic, int nbr_mot)
{
	ifstream fichier(nom_fic);
	if (fichier)
	{
		string ligne1;
		int nombre_mot = 0;
		while (getline(fichier, ligne1))
		{
			srand(time(0));
			nombre_mot++;
			int nombre_al = rand() % nbr_mot;
			stringstream ss(ligne1);
			vector<string> mots;
			string mot;
			if (nombre_mot == nombre_al)
			{
				ss >> mot;
				mots.push_back(mot);
				return mots.back();
				break;
				//cout << "le  mot aleatoire tire est : " << mots.back() << endl;
				//cout << "le numero du mot tire est : " << nombre_mot << endl;
			}
			//else
			//{
			//	getline(fichier2, ligne1);
			//}
		}
	}
}




//cout << ligne << endl;
//int c_mot = 0;
//cout << "nombre de mots : " << c_mot << endl;
int main()
{
	string fichier = GetNomFichier();
	cout << "nom du fichier : " << fichier << endl;
	int nbr_mot = GetNombreLigne(fichier);
	cout << "nombre de mots = " << nbr_mot << endl;
	cout << "le mot tire est : " << GetMot(fichier, nbr_mot);
}
	
*/