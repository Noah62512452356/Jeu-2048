#include "Grille.h"
#include <iostream>
#include <iomanip>

using namespace std;

Grille::Grille(int t) 
    : taille(t), cellules(t, vector<Tuile>(t, Tuile(0))) {}

void Grille::resetFusionFlags() {
    for(int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            cellules[i][j].resetFusion();
}

void Grille::afficher() const {
    cout << "2048 : BONJOUR \n\n";

    for(int i = 0; i < taille; i++) {
        for(int j = 0; j < taille; j++) {
            int val = cellules[i][j].getValeur();
            if(val == 0)
                cout << setw(5) << ".";
            else
                cout << setw(5) << val;
        }
        cout << endl;
    }
    cout << endl;
}

void Grille::ajouterTuileAleatoire() {
    vector<pair<int,int>> vides;
    for(int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            if(cellules[i][j].getValeur() == 0)
                vides.push_back({i,j});

    if(vides.empty())
        return;

    int choix = rand() % vides.size();
    int val = (rand() % 10 == 0) ? 4 : 2;
    cellules[vides[choix].first][vides[choix].second].setValeur(val);
}

bool Grille::peutBouger() const {
    for(int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            if(cellules[i][j].getValeur() == 0)
                return true;

    for(int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++) {
            if(j+1 < taille && 
                cellules[i][j].getValeur() == cellules[i][j+1].getValeur())
                return true;

            if(i+1 < taille && 
                cellules[i][j].getValeur() == cellules[i+1][j].getValeur())
                return true;
        }

    return false;
}

bool Grille::deplacerGauche() {
    bool change = false;
    resetFusionFlags();

    for(int i = 0; i < taille; i++) {
        vector<int> ligne;

        for(int j = 0; j < taille; j++) {
            int val = cellules[i][j].getValeur();
            if(val != 0)
                ligne.push_back(val);
        }

        for(int j = 0; j < (int)ligne.size() - 1; j++) {
            if(ligne[j] == ligne[j+1]) {
                ligne[j] *= 2;
                ligne.erase(ligne.begin()+j+1);
            }
        }

        while(ligne.size() < taille)
            ligne.push_back(0);

        for(int j = 0; j < taille; j++) {
            if(cellules[i][j].getValeur() != ligne[j]) {
                cellules[i][j].setValeur(ligne[j]);
                change = true;
            }
        }
    }

    return change;
}

bool Grille::deplacerDroite() {
    bool change = false;
    resetFusionFlags();

    for(int i = 0; i < taille; i++) {
        vector<int> ligne;

        for(int j = taille - 1; j >= 0; j--) {
            int val = cellules[i][j].getValeur();
            if(val != 0)
                ligne.push_back(val);
        }

        for(int j = 0; j < (int)ligne.size() - 1; j++) {
            if(ligne[j] == ligne[j+1]) {
                ligne[j] *= 2;
                ligne.erase(ligne.begin()+j+1);
            }
        }

        while(ligne.size() < taille)
            ligne.push_back(0);

        for(int j = taille-1, k = 0; j >= 0; j--, k++) {
            if(cellules[i][j].getValeur() != ligne[k]) {
                cellules[i][j].setValeur(ligne[k]);
                change = true;
            }
        }
    }

    return change;
}

bool Grille::deplacerHaut() {
    bool change = false;
    resetFusionFlags();

    for(int j = 0; j < taille; j++) {
        vector<int> col;

        for(int i = 0; i < taille; i++) {
            int val = cellules[i][j].getValeur();
            if(val != 0)
                col.push_back(val);
        }

        for(int i = 0; i < (int)col.size() - 1; i++) {
            if(col[i] == col[i+1]) {
                col[i] *= 2;
                col.erase(col.begin()+i+1);
            }
        }

        while(col.size() < taille)
            col.push_back(0);

        for(int i = 0; i < taille; i++) {
            if(cellules[i][j].getValeur() != col[i]) {
                cellules[i][j].setValeur(col[i]);
                change = true;
            }
        }
    }

    return change;
}

bool Grille::deplacerBas() {
    bool change = false;
    resetFusionFlags();

    for(int j = 0; j < taille; j++) {
        vector<int> col;

        for(int i = taille-1; i >= 0; i--) {
            int val = cellules[i][j].getValeur();
            if(val != 0)
                col.push_back(val);
        }

        for(int i = 0; i < (int)col.size() - 1; i++) {
            if(col[i] == col[i+1]) {
                col[i] *= 2;
                col.erase(col.begin()+i+1);
            }
        }

        while(col.size() < taille)
            col.push_back(0);

        for(int i = taille-1, k = 0; i >= 0; i--, k++) {
            if(cellules[i][j].getValeur() != col[k]) {
                cellules[i][j].setValeur(col[k]);
                change = true;
            }
        }
    }

    return change;
}

bool Grille::victoire() const {
    for(int i = 0; i < taille; i++)
        for(int j = 0; j < taille; j++)
            if(cellules[i][j].getValeur() >= 2048)
                return true;
    return false;
}
