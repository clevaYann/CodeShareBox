#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<ctime>
using namespace std;




string GetNomFichierAl()
{
	ifstream fichier("C:\\tmp\\MOTS\\mots_4.txt");
	srand(time(0));
	if (fichier)
	{
		int nombre_al = rand() % 8 + 4;
		string nombre = to_string(nombre_al);
		string ligne;
		while (getline(fichier, ligne))
		{
			return "C:\\tmp\\MOTS\\mots_" + nombre + ".txt";
		}
	}

}
int GetNombreMotAl(ifstream& fichier)
{
	string ligne;
	int nbr_mot = 0;
	if (true)
	{
		while (getline(fichier, ligne))
		{
			nbr_mot++;
		}return nbr_mot;
	}
}
string GetMotAl(ifstream& fichier, int nb_mot)
{
	if (fichier)
	{
		string ligne1;
		int nombre_mot = 0;
		while(getline(fichier, ligne1))
		{
			srand(time(0));
			nombre_mot++;
			int nombre_al = rand() % nb_mot ;
			stringstream ss(ligne1);
			vector<string> tab_mot;
			string mot;
			if (nombre_mot == nombre_al)
			{
				ss >> mot;
				tab_mot.push_back(mot);
				return tab_mot.back();
				break;
			//cout << "le  mot aleatoire tire est : " << mots.back() << endl;
			//cout << "le numero du mot tire est : " << nombre_mot << endl;
			}
			//else
			//{
			//	getline(fichier, ligne1);
			//}
		}
	}
}
int main()
{
	

	static string nom_fic = GetNomFichierAl();
	ifstream fichier1(nom_fic);
	int nombre = GetNombreMotAl(fichier1);
	cout << "Le nom du fichier est : " << nom_fic << endl;
	cout << "Nombre de mots : " <<  nombre << endl;
	ifstream fichier2(nom_fic);
	string mot_al = GetMotAl(fichier2, nombre);
	cout << "Le mot tire est : " << mot_al << endl;
	return 0;
}