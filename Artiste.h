#ifndef ARTISTE_H
#define ARTISTE_H

#include "Date.h"
#include <string>
using namespace std;

class Artiste {
private:
    int identifiant;
    string nomScene;
    string genreMusical;
    string paysOrigine;
    double cachet;
    Date dateInscription;
    
public:
    Artiste();
    
    void saisir();
    void afficher() const;
    
    // Getters
    int getIdentifiant() const { return identifiant; }
    string getNomScene() const { return nomScene; }
    string getGenreMusical() const { return genreMusical; }
    string getPaysOrigine() const { return paysOrigine; }
    double getCachet() const { return cachet; }
    Date getDateInscription() const { return dateInscription; }
    
    // Setters
    void setIdentifiant(int id) { identifiant = id; }
    void setNomScene(const string& nom) { nomScene = nom; }
    void setGenreMusical(const string& genre) { genreMusical = genre; }
    void setPaysOrigine(const string& pays) { paysOrigine = pays; }
    void setCachet(double c) { cachet = c; }
    void setDateInscription(const Date& date) { dateInscription = date; }
};

#endif