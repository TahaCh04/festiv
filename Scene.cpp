#include "Scene.h"
#include <iostream>
#include <algorithm>

Scene::Scene() : code(""), nom(""), nombreMaxArtistes(0) {}

void Scene::saisir() {
    cout << "=== Saisie d'une scene ===" << endl;
    cout << "Code : "; cin >> code;
    cin.ignore();
    cout << "Nom : "; getline(cin, nom);
    cout << "Nombre maximal d'artistes : "; cin >> nombreMaxArtistes;
    cout << "Technicien responsable :" << endl;
    technicienResponsable.saisir();
    cout << "Date de mise en service :" << endl;
    dateMiseEnService.saisir();
}

void Scene::afficher() const {
    cout << "=== Scene ===" << endl;
    cout << "Code : " << code << endl;
    cout << "Nom : " << nom << endl;
    cout << "Capacite max : " << nombreMaxArtistes << endl;
    cout << "Artistes programmes : " << artistesProgrammes.size() << endl;
    cout << "Date mise en service : "; 
    dateMiseEnService.afficher(); 
    cout << endl;
}

bool Scene::artisteExiste(int idArtiste) const {
    for (const auto& artiste : artistesProgrammes) {
        if (artiste.getIdentifiant() == idArtiste) {
            return true;
        }
    }
    return false;
}

bool Scene::ajouterArtiste(const Artiste& artiste) {
    if (artisteExiste(artiste.getIdentifiant())) {
        cout << "Erreur : L'artiste existe deja dans cette scene." << endl;
        return false;
    }
    
    if (artistesProgrammes.size() >= nombreMaxArtistes) {
        cout << "Erreur : Capacite maximale atteinte." << endl;
        return false;
    }
    
    artistesProgrammes.push_back(artiste);
    cout << "Artiste ajoute avec succes." << endl;
    return true;
}

void Scene::modifierNom(const string& nouveauNom) {
    nom = nouveauNom;
    cout << "Nom modifie avec succes." << endl;
}

void Scene::afficherArtistesRecents() const {
    cout << "=== Artistes recemment inscrits (< 1 an) ===" << endl;
    bool found = false;
    for (const auto& artiste : artistesProgrammes) {
        if (artiste.getDateInscription().estDansAnneeEcoulee()) {
            artiste.afficher();
            found = true;
        }
    }
    if (!found) {
        cout << "Aucun artiste recemment inscrit." << endl;
    }
}

int Scene::calculerAnciennete() const {
    return dateMiseEnService.differenceAnnees();
}

bool Scene::supprimerArtiste(int idArtiste) {
    for (auto it = artistesProgrammes.begin(); it != artistesProgrammes.end(); ++it) {
        if (it->getIdentifiant() == idArtiste) {
            artistesProgrammes.erase(it);
            cout << "Artiste supprime avec succes." << endl;
            return true;
        }
    }
    cout << "Erreur : Artiste non trouve." << endl;
    return false;
}

void Scene::afficherSceneComplete() const {
    cout << "\n=== Details de la scene ===" << endl;
    cout << "Code : " << code << endl;
    cout << "Nom : " << nom << endl;
    cout << "Technicien responsable : " << technicienResponsable.getNomComplet() << endl;
    cout << "Capacite : " << artistesProgrammes.size() << "/" << nombreMaxArtistes << endl;
    cout << "Date mise en service : "; 
    dateMiseEnService.afficher();
    cout << " (Anciennete : " << calculerAnciennete() << " ans)" << endl;
    
    cout << "\n=== Artistes programmes ===" << endl;
    if (artistesProgrammes.empty()) {
        cout << "Aucun artiste programme." << endl;
    } else {
        for (const auto& artiste : artistesProgrammes) {
            artiste.afficher();
            cout << "------------------------" << endl;
        }
    }
}