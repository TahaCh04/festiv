#ifndef GESTIONFESTIVAL_H
#define GESTIONFESTIVAL_H

#include "Scene.h"
#include <vector>
using namespace std;

// Fonctions pour la gestion du tableau de scenes
bool sceneExiste(const vector<Scene>& scenes, const string& code);
void ajouterScene(vector<Scene>& scenes);
void modifierScene(vector<Scene>& scenes, const string& code);
void supprimerScene(vector<Scene>& scenes, const string& code);
void afficherToutesScenes(const vector<Scene>& scenes);
vector<Scene> scenesOperationnelles5Ans(const vector<Scene>& scenes);
void afficherScenesParTechnicien(const vector<Scene>& scenes, const string& nomTechnicien);

#endif