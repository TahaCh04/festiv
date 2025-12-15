#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Date.h"
#include <string>
using namespace std;

class Technicien {
private:
    int identifiant;
    string nom;
    string prenom;
    string specialite;
    double salaire;
    Date dateEmbauche;
    
public:
    Technicien();
    
    void saisir();
    void afficher() const;
    
    // Getters
    int getIdentifiant() const { return identifiant; }
    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }
    string getSpecialite() const { return specialite; }
    double getSalaire() const { return salaire; }
    Date getDateEmbauche() const { return dateEmbauche; }
    
    // Setters
    void setIdentifiant(int id) { identifiant = id; }
    void setNom(const string& n) { nom = n; }
    void setPrenom(const string& p) { prenom = p; }
    void setSpecialite(const string& s) { specialite = s; }
    void setSalaire(double s) { salaire = s; }
    void setDateEmbauche(const Date& date) { dateEmbauche = date; }
    
    string getNomComplet() const { return prenom + " " + nom; }
};

#endif