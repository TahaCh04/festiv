#include "GestionFestival.h"
#include "Artiste.h"
#include "Technicien.h"
#include "Scene.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void afficherMenuPrincipal();
void afficherMenuScene();
void afficherMenuArtiste();
void afficherMenuTechnicien();

void viderBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Scene> scenes;
    vector<Artiste> artistes;
    vector<Technicien> techniciens;
    
    int choix = 0;
    
    do {
        afficherMenuPrincipal();
        cout << "Votre choix : ";
        
        // Vérifier si l'entrée est valide
        if (!(cin >> choix)) {
            viderBuffer();
            cout << "Entree invalide! Veuillez entrer un nombre." << endl;
            continue;
        }
        
        viderBuffer(); // Vider le buffer après chaque saisie
        
        switch (choix) {
            case 1: { // Gestion des scenes
                int choixScene = 0;
                do {
                    afficherMenuScene();
                    cout << "Votre choix : ";
                    
                    if (!(cin >> choixScene)) {
                        viderBuffer();
                        cout << "Entree invalide!" << endl;
                        continue;
                    }
                    
                    viderBuffer();
                    
                    switch (choixScene) {
                        case 1: {
                            ajouterScene(scenes);
                            break;
                        }
                        case 2: {
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            string code;
                            cout << "Code de la scene a modifier : ";
                            getline(cin, code);
                            modifierScene(scenes, code);
                            break;
                        }
                        case 3: {
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            string code;
                            cout << "Code de la scene a supprimer : ";
                            getline(cin, code);
                            supprimerScene(scenes, code);
                            break;
                        }
                        case 4: {
                            afficherToutesScenes(scenes);
                            break;
                        }
                        case 5: {
                            vector<Scene> scenes5Ans = scenesOperationnelles5Ans(scenes);
                            cout << "\n=== Scenes operationnelles depuis plus de 5 ans ===" << endl;
                            if (scenes5Ans.empty()) {
                                cout << "Aucune scene." << endl;
                            } else {
                                for (const auto& scene : scenes5Ans) {
                                    scene.afficher();
                                }
                            }
                            break;
                        }
                        case 6: {
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            string nomTech;
                            cout << "Nom du technicien : ";
                            getline(cin, nomTech);
                            afficherScenesParTechnicien(scenes, nomTech);
                            break;
                        }
                        case 7: {
                            cout << "Retour au menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Choix invalide. Veuillez choisir entre 1 et 7." << endl;
                        }
                    }
                    
                    if (choixScene != 7) {
                        cout << "\nAppuyez sur Entree pour continuer...";
                        cin.get();
                    }
                    
                } while (choixScene != 7);
                break;
            }
            
            case 2: { // Gestion des artistes
                int choixArtiste = 0;
                do {
                    afficherMenuArtiste();
                    cout << "Votre choix : ";
                    
                    if (!(cin >> choixArtiste)) {
                        viderBuffer();
                        cout << "Entree invalide!" << endl;
                        continue;
                    }
                    
                    viderBuffer();
                    
                    switch (choixArtiste) {
                        case 1: {
                            Artiste nouvelArtiste;
                            nouvelArtiste.saisir();
                            artistes.push_back(nouvelArtiste);
                            break;
                        }
                        case 2: {
                            if (artistes.empty()) {
                                cout << "Aucun artiste disponible." << endl;
                                break;
                            }
                            cout << "\n=== Liste des artistes ===" << endl;
                            for (const auto& artiste : artistes) {
                                artiste.afficher();
                                cout << "-------------------" << endl;
                            }
                            break;
                        }
                        case 3: {
                            // Ajouter un artiste a une scene
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            
                            if (artistes.empty()) {
                                cout << "Aucun artiste disponible." << endl;
                                break;
                            }
                            
                            string codeScene;
                            cout << "Code de la scene : ";
                            getline(cin, codeScene);
                            
                            bool sceneTrouvee = false;
                            for (auto& scene : scenes) {
                                if (scene.getCode() == codeScene) {
                                    sceneTrouvee = true;
                                    
                                    // Afficher les artistes disponibles
                                    cout << "\n=== Artistes disponibles ===" << endl;
                                    for (const auto& artiste : artistes) {
                                        cout << "ID: " << artiste.getIdentifiant() 
                                             << " - " << artiste.getNomScene() << endl;
                                    }
                                    
                                    int idArtiste;
                                    cout << "\nID de l'artiste a ajouter : ";
                                    if (!(cin >> idArtiste)) {
                                        viderBuffer();
                                        cout << "ID invalide!" << endl;
                                        break;
                                    }
                                    viderBuffer();
                                    
                                    // Trouver l'artiste
                                    Artiste* artisteAAjouter = nullptr;
                                    for (auto& artiste : artistes) {
                                        if (artiste.getIdentifiant() == idArtiste) {
                                            artisteAAjouter = &artiste;
                                            break;
                                        }
                                    }
                                    
                                    if (artisteAAjouter) {
                                        scene.ajouterArtiste(*artisteAAjouter);
                                    } else {
                                        cout << "Artiste non trouve." << endl;
                                    }
                                    break;
                                }
                            }
                            
                            if (!sceneTrouvee) {
                                cout << "Scene non trouvee." << endl;
                            }
                            break;
                        }
                        case 4: {
                            // Afficher artistes recents d'une scene
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            
                            string codeScene;
                            cout << "Code de la scene : ";
                            getline(cin, codeScene);
                            
                            bool sceneTrouvee = false;
                            for (const auto& scene : scenes) {
                                if (scene.getCode() == codeScene) {
                                    sceneTrouvee = true;
                                    scene.afficherArtistesRecents();
                                    break;
                                }
                            }
                            
                            if (!sceneTrouvee) {
                                cout << "Scene non trouvee." << endl;
                            }
                            break;
                        }
                        case 5: {
                            // Supprimer artiste d'une scene
                            if (scenes.empty()) {
                                cout << "Aucune scene disponible." << endl;
                                break;
                            }
                            
                            string codeScene;
                            cout << "Code de la scene : ";
                            getline(cin, codeScene);
                            
                            bool sceneTrouvee = false;
                            for (auto& scene : scenes) {
                                if (scene.getCode() == codeScene) {
                                    sceneTrouvee = true;
                                    
                                    int idArtiste;
                                    cout << "ID de l'artiste a supprimer : ";
                                    if (!(cin >> idArtiste)) {
                                        viderBuffer();
                                        cout << "ID invalide!" << endl;
                                        break;
                                    }
                                    viderBuffer();
                                    
                                    scene.supprimerArtiste(idArtiste);
                                    break;
                                }
                            }
                            
                            if (!sceneTrouvee) {
                                cout << "Scene non trouvee." << endl;
                            }
                            break;
                        }
                        case 6: {
                            cout << "Retour au menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Choix invalide. Veuillez choisir entre 1 et 6." << endl;
                        }
                    }
                    
                    if (choixArtiste != 6) {
                        cout << "\nAppuyez sur Entree pour continuer...";
                        cin.get();
                    }
                    
                } while (choixArtiste != 6);
                break;
            }
            
            case 3: { // Gestion des techniciens
                int choixTechnicien = 0;
                do {
                    afficherMenuTechnicien();
                    cout << "Votre choix : ";
                    
                    if (!(cin >> choixTechnicien)) {
                        viderBuffer();
                        cout << "Entree invalide!" << endl;
                        continue;
                    }
                    
                    viderBuffer();
                    
                    switch (choixTechnicien) {
                        case 1: {
                            Technicien nouveauTechnicien;
                            nouveauTechnicien.saisir();
                            techniciens.push_back(nouveauTechnicien);
                            break;
                        }
                        case 2: {
                            if (techniciens.empty()) {
                                cout << "Aucun technicien disponible." << endl;
                                break;
                            }
                            cout << "\n=== Liste des techniciens ===" << endl;
                            for (const auto& technicien : techniciens) {
                                technicien.afficher();
                                cout << "-------------------" << endl;
                            }
                            break;
                        }
                        case 3: {
                            cout << "Retour au menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Choix invalide. Veuillez choisir entre 1 et 3." << endl;
                        }
                    }
                    
                    if (choixTechnicien != 3) {
                        cout << "\nAppuyez sur Entree pour continuer...";
                        cin.get();
                    }
                    
                } while (choixTechnicien != 3);
                break;
            }
            
            case 4: {
                cout << "\n=== Test de toutes les fonctionnalites ===" << endl;
                
                // Creation de donnees de test
                cout << "\n1. Creation d'un artiste test..." << endl;
                Artiste artiste1;
                artiste1.setIdentifiant(1);
                artiste1.setNomScene("Rock Band");
                artiste1.setGenreMusical("Rock");
                artiste1.setPaysOrigine("USA");
                artiste1.setCachet(5000);
                artiste1.setDateInscription(Date(1, 1, 2023));
                
                cout << "\n2. Creation d'un technicien test..." << endl;
                Technicien tech1;
                tech1.setIdentifiant(1);
                tech1.setNom("Dupont");
                tech1.setPrenom("Jean");
                tech1.setSpecialite("Son");
                tech1.setSalaire(3000);
                tech1.setDateEmbauche(Date(1, 1, 2018));
                
                cout << "\n3. Creation d'une scene test..." << endl;
                Scene scene1;
                scene1.setCode("S01");
                scene1.setNom("Scene Principale");
                scene1.setTechnicienResponsable(tech1);
                scene1.setNombreMaxArtistes(10);
                scene1.setDateMiseEnService(Date(1, 1, 2018));
                
                // Test des methodes
                cout << "\n4. Test ajout artiste a scene:" << endl;
                scene1.ajouterArtiste(artiste1);
                
                cout << "\n5. Test verification existence artiste:" << endl;
                if (scene1.artisteExiste(1)) {
                    cout << "Artiste existe." << endl;
                }
                
                cout << "\n6. Test affichage artistes recents:" << endl;
                scene1.afficherArtistesRecents();
                
                cout << "\n7. Test anciennete scene:" << endl;
                cout << "Anciennete: " << scene1.calculerAnciennete() << " ans" << endl;
                
                cout << "\n8. Test affichage complet scene:" << endl;
                scene1.afficherSceneComplete();
                
                scenes.push_back(scene1);
                artistes.push_back(artiste1);
                techniciens.push_back(tech1);
                
                cout << "\n=== Tests termines ===" << endl;
                cout << "\nAppuyez sur Entree pour continuer...";
                cin.get();
                break;
            }
            
            case 5: {
                cout << "Au revoir!" << endl;
                break;
            }
            
            default: {
                cout << "Choix invalide. Veuillez choisir entre 1 et 5." << endl;
                cout << "\nAppuyez sur Entree pour continuer...";
                cin.get();
            }
        }
        
    } while (choix != 5);
    
    return 0;
}

void afficherMenuPrincipal() {
    cout << "\n========================================" << endl;
    cout << "    GESTION FESTIVAL DE MUSIQUE" << endl;
    cout << "========================================" << endl;
    cout << "1. Gestion des scenes" << endl;
    cout << "2. Gestion des artistes" << endl;
    cout << "3. Gestion des techniciens" << endl;
    cout << "4. Tester toutes les fonctionnalites" << endl;
    cout << "5. Quitter" << endl;
    cout << "========================================" << endl;
}

void afficherMenuScene() {
    cout << "\n----------------------------------------" << endl;
    cout << "        GESTION DES SCENES" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Ajouter une scene" << endl;
    cout << "2. Modifier une scene" << endl;
    cout << "3. Supprimer une scene" << endl;
    cout << "4. Afficher toutes les scenes" << endl;
    cout << "5. Scenes operationnelles > 5 ans" << endl;
    cout << "6. Scenes par technicien" << endl;
    cout << "7. Retour menu principal" << endl;
    cout << "----------------------------------------" << endl;
}

void afficherMenuArtiste() {
    cout << "\n----------------------------------------" << endl;
    cout << "       GESTION DES ARTISTES" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Ajouter un artiste" << endl;
    cout << "2. Afficher tous les artistes" << endl;
    cout << "3. Ajouter artiste a une scene" << endl;
    cout << "4. Afficher artistes recents d'une scene" << endl;
    cout << "5. Supprimer artiste d'une scene" << endl;
    cout << "6. Retour menu principal" << endl;
    cout << "----------------------------------------" << endl;
}

void afficherMenuTechnicien() {
    cout << "\n----------------------------------------" << endl;
    cout << "      GESTION DES TECHNICIENS" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Ajouter un technicien" << endl;
    cout << "2. Afficher tous les techniciens" << endl;
    cout << "3. Retour menu principal" << endl;
    cout << "----------------------------------------" << endl;
}