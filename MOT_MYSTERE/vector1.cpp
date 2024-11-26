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
    // Déclaration d'un tableau de la classe vector contenant 5 ou 6 mots de type string
    vector<string> mots = { "banane", "orange", "pomme", "fraise", "cerise" };

    // Déclaration d'un index aléatoire du tableau de mots
    srand(time(0));
    int tirage = rand() % mots.size();
    //Déclaration d'une variable de saisie
    string motSaisi;

    // Stockage du mot mystère tiré avec l'index tirage dans la variable motMystere
    string fruits = mots[tirage];

    // Déclaration initialisation à 0 d'une variable nbEssais
    int nbEssais = 0;

    // Récupération et stockage de la taille du mot mystère tiré
    int tailleMot = fruits.length();

    // Création d'une variable 'indices' chaîne de caractères contenant autant de ? que de lettres attendues dans le mot mystère
    string indices(tailleMot, '?');

    // Tant que tous les caractères ne sont pas trouvés
while (indices != fruits)
{
    // IHM de saisie du mot
    cout << "Devine le mot : " << indices << endl;

    // Incrémentation du nombre d'essais
        nbEssais++;

    // Contrôle du mot saisi
    cout << "Saisi un mot : ";
    cin >> motSaisi;

    // Vérification des caractères et mise à jour de 'indices'
    for (int i = 0; i < tailleMot; i++) 
    {
        if (motSaisi.find(fruits[i]) != string::npos)
        {
            indices[i] = fruits[i];
        }
    }
}

    // Affichage des félicitations et du nombre d'essais
cout << "Bravo jarlin ! tu as trouvé le mot '" << fruits << "' en " << nbEssais << " essais." << endl;

return 0;
}
