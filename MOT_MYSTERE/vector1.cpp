#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

#define ACCENT_VALID SetConsoleOutputCP(CP_UTF8);

int main() 
{
    ACCENT_VALID;
    // D�claration d'un tableau de la classe vector contenant 5 ou 6 mots de type string
    vector<string> mots = { "banane", "orange", "pomme", "fraise", "cerise" };

    // D�claration d'un index al�atoire du tableau de mots
    srand(time(0));
    int tirage = rand() % mots.size();
    //D�claration d'une variable de saisie
    string motSaisi;

    // Stockage du mot myst�re tir� avec l'index tirage dans la variable motMystere
    string fruits = mots[tirage];

    // D�claration initialisation � 0 d'une variable nbEssais
    int nbEssais = 0;

    // R�cup�ration et stockage de la taille du mot myst�re tir�
    int tailleMot = fruits.length();

    // Cr�ation d'une variable 'indices' cha�ne de caract�res contenant autant de ? que de lettres attendues dans le mot myst�re
    string indices(tailleMot, '?');

    // Tant que tous les caract�res ne sont pas trouv�s
while (indices != fruits)
{
    // IHM de saisie du mot
    cout << "Devine le mot : " << indices << endl;

    // Incr�mentation du nombre d'essais
        nbEssais++;

    // Contr�le du mot saisi
    cout << "Saisi un mot : ";
    cin >> motSaisi;

    // V�rification des caract�res et mise � jour de 'indices'
    for (int i = 0; i < tailleMot; i++) 
    {
        if (motSaisi.find(fruits[i]) != string::npos)
        {
            indices[i] = fruits[i];
        }
    }
}

    // Affichage des f�licitations et du nombre d'essais
cout << "Bravo jarlin ! tu as trouv� le mot '" << fruits << "' en " << nbEssais << " essais." << endl;

return 0;
}
