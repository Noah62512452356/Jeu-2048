#include "Jeu.h"
#include <iostream>
#include <ctime>

using namespace std;

Jeu::Jeu() : fini(false) {
    srand(time(nullptr));
    grille.ajouterTuileAleatoire();
    grille.ajouterTuileAleatoire();
}

void Jeu::bouclePrincipale() {
    while(!fini) {
        grille.afficher();

        cout << "(Z = Haut, Q = Gauche, S = Bas, D = Droite) : ";
        char c;
        cin >> c;
        bool modif = false;

        switch(tolower(c)) {
            case 'q':
                modif = grille.deplacerGauche();
                break;
            case 'd':
                modif = grille.deplacerDroite();
                break;
            case 'z':
                modif = grille.deplacerHaut();
                break;
            case 's':
                modif = grille.deplacerBas();
                break;
            default:
                continue;
        }

        if(modif)
            grille.ajouterTuileAleatoire();

        if(grille.victoire()) {
            grille.afficher();
            cout << "Gagner 2048 atteint.\n";
            fini = true;
        }
        else if(!grille.peutBouger()) {
            grille.afficher();
            cout << "Perdu aucun mouvement.\n";
            fini = true;
        }
    }
}
