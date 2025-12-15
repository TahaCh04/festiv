#include "Artiste.h"
#include <iostream>

Artiste::Artiste() : identifiant(0), nomScene(""), genreMusical(""), 
                     paysOrigine(""), cachet(0.0) {}

void Artiste::saisir() {
    cout << "=== Saisie d'un artiste ===" << endl;
    cout << "Identifiant : "; cin >> identifiant;
    cin.ignore();
    cout << "Nom de scene : "; getline(cin, nomScene);
    cout << "Genre musical : "; getline(cin, genreMusical);
    cout << "Pays d'origine : "; getline(cin, paysOrigine);
    cout << "Cachet : "; cin >> cachet;
    cout << "Date d'inscription :" << endl;
    dateInscription.saisir();
}

void Artiste::afficher() const {
    cout << "=== Artiste ===" << endl;
    cout << "ID : " << identifiant << endl;
    cout << "Nom de scene : " << nomScene << endl;
    cout << "Genre : " << genreMusical << endl;
    cout << "Pays : " << paysOrigine << endl;
    cout << "Cachet : " << cachet << " €" << endl;
    cout << "Date inscription : "; 
    dateInscription.afficher(); 
    cout << endl;
}