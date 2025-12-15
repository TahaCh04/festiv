#include "Technicien.h"
#include <iostream>

Technicien::Technicien() : identifiant(0), nom(""), prenom(""), 
                           specialite(""), salaire(0.0) {}

void Technicien::saisir() {
    cout << "=== Saisie d'un technicien ===" << endl;
    cout << "Identifiant : "; cin >> identifiant;
    cin.ignore();
    cout << "Nom : "; getline(cin, nom);
    cout << "Prenom : "; getline(cin, prenom);
    cout << "Specialite : "; getline(cin, specialite);
    cout << "Salaire : "; cin >> salaire;
    cout << "Date d'embauche :" << endl;
    dateEmbauche.saisir();
}

void Technicien::afficher() const {
    cout << "=== Technicien ===" << endl;
    cout << "ID : " << identifiant << endl;
    cout << "Nom complet : " << getNomComplet() << endl;
    cout << "Specialite : " << specialite << endl;
    cout << "Salaire : " << salaire << " €" << endl;
    cout << "Date embauche : "; 
    dateEmbauche.afficher(); 
    cout << endl;
}