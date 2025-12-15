#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
using namespace std;

class Date {
private:
    int jour;
    int mois;
    int annee;
    
public:
    Date();
    Date(int j, int m, int a);
    
    void saisir();
    void afficher() const;
    int differenceAnnees() const;
    bool estDansAnneeEcoulee() const;
    
    // Getters
    int getJour() const { return jour; }
    int getMois() const { return mois; }
    int getAnnee() const { return annee; }
    
    // Setters
    void setJour(int j) { jour = j; }
    void setMois(int m) { mois = m; }
    void setAnnee(int a) { annee = a; }
};

#endif