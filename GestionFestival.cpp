#include "GestionFestival.h"
#include <iostream>
#include <algorithm>

bool sceneExiste(const vector<Scene>& scenes, const string& code) {
    for (const auto& scene : scenes) {
        if (scene.getCode() == code) {
            return true;
        }
    }
    return false;
}

void ajouterScene(vector<Scene>& scenes) {
    Scene nouvelleScene;
    nouvelleScene.saisir();
    
    if (sceneExiste(scenes, nouvelleScene.getCode())) {
        cout << "Erreur : Une scene avec ce code existe deja." << endl;
        return;
    }
    
    scenes.push_back(nouvelleScene);
    cout << "Scene ajoutee avec succes." << endl;
}

void modifierScene(vector<Scene>& scenes, const string& code) {
    for (auto& scene : scenes) {
        if (scene.getCode() == code) {
            cout << "=== Modification de la scene " << code << " ===" << endl;
            
            string nouveauNom;
            cout << "Nouveau nom (ou Entree pour conserver) : ";
            cin.ignore();
            getline(cin, nouveauNom);
            if (!nouveauNom.empty()) {
                scene.setNom(nouveauNom);
            }
            
            char choix;
            cout << "Modifier le technicien responsable ? (o/n) : ";
            cin >> choix;
            if (choix == 'o' || choix == 'O') {
                Technicien nouveauTech;
                nouveauTech.saisir();
                scene.setTechnicienResponsable(nouveauTech);
            }
            
            int nouvelleCapacite;
            cout << "Nouvelle capacite max (0 pour conserver) : ";
            cin >> nouvelleCapacite;
            if (nouvelleCapacite > 0) {
                scene.setNombreMaxArtistes(nouvelleCapacite);
            }
            
            cout << "Scene modifiee avec succes." << endl;
            return;
        }
    }
    cout << "Erreur : Scene non trouvee." << endl;
}

void supprimerScene(vector<Scene>& scenes, const string& code) {
    for (auto it = scenes.begin(); it != scenes.end(); ++it) {
        if (it->getCode() == code) {
            scenes.erase(it);
            cout << "Scene supprimee avec succes." << endl;
            return;
        }
    }
    cout << "Erreur : Scene non trouvee." << endl;
}

void afficherToutesScenes(const vector<Scene>& scenes) {
    cout << "\n=== Liste de toutes les scenes ===" << endl;
    if (scenes.empty()) {
        cout << "Aucune scene disponible." << endl;
        return;
    }
    
    for (const auto& scene : scenes) {
        scene.afficherSceneComplete();
        cout << "=================================" << endl;
    }
}

vector<Scene> scenesOperationnelles5Ans(const vector<Scene>& scenes) {
    vector<Scene> resultat;
    for (const auto& scene : scenes) {
        if (scene.calculerAnciennete() > 5) {
            resultat.push_back(scene);
        }
    }
    return resultat;
}

void afficherScenesParTechnicien(const vector<Scene>& scenes, const string& nomTechnicien) {
    cout << "\n=== Scenes sous la direction de " << nomTechnicien << " ===" << endl;
    bool found = false;
    
    for (const auto& scene : scenes) {
        Technicien tech = scene.getTechnicienResponsable();
        if (tech.getNom() == nomTechnicien || tech.getPrenom() + " " + tech.getNom() == nomTechnicien) {
            scene.afficher();
            found = true;
        }
    }
    
    if (!found) {
        cout << "Aucune scene trouvee pour ce technicien." << endl;
    }
}