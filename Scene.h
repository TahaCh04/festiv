#ifndef SCENE_H
#define SCENE_H

#include "Artiste.h"
#include "Technicien.h"
#include <vector>
using namespace std;

class Scene {
private:
    string code;
    string nom;
    Technicien technicienResponsable;
    int nombreMaxArtistes;
    vector<Artiste> artistesProgrammes;
    Date dateMiseEnService;
    
public:
    Scene();
    
    void saisir();
    void afficher() const;
    
    // Methodes demandees
    bool artisteExiste(int idArtiste) const;
    bool ajouterArtiste(const Artiste& artiste);
    void modifierNom(const string& nouveauNom);
    void afficherArtistesRecents() const;
    int calculerAnciennete() const;
    bool supprimerArtiste(int idArtiste);
    void afficherSceneComplete() const;
    
    // Getters
    string getCode() const { return code; }
    string getNom() const { return nom; }
    Technicien getTechnicienResponsable() const { return technicienResponsable; }
    int getNombreMaxArtistes() const { return nombreMaxArtistes; }
    vector<Artiste> getArtistesProgrammes() const { return artistesProgrammes; }
    Date getDateMiseEnService() const { return dateMiseEnService; }
    
    // Setters
    void setCode(const string& c) { code = c; }
    void setNom(const string& n) { nom = n; }
    void setTechnicienResponsable(const Technicien& t) { technicienResponsable = t; }
    void setNombreMaxArtistes(int n) { nombreMaxArtistes = n; }
    void setDateMiseEnService(const Date& date) { dateMiseEnService = date; }
};

#endif