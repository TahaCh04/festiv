#include "Date.h"

Date::Date() : jour(1), mois(1), annee(2000) {}

Date::Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

void Date::saisir() {
    cout << "Jour : "; cin >> jour;
    cout << "Mois : "; cin >> mois;
    cout << "Annee : "; cin >> annee;
}

void Date::afficher() const {
    cout << jour << "/" << mois << "/" << annee;
}

int Date::differenceAnnees() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int anneeActuelle = 1900 + ltm->tm_year;
    int moisActuel = 1 + ltm->tm_mon;
    int jourActuel = ltm->tm_mday;
    
    int diff = anneeActuelle - annee;
    if (moisActuel < mois || (moisActuel == mois && jourActuel < jour)) {
        diff--;
    }
    return diff;
}

bool Date::estDansAnneeEcoulee() const {
    return differenceAnnees() < 1;
}