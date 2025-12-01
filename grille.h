#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Tuile.h"

class Grille {
private:
    std::vector<std::vector<Tuile>> cellules;
    int taille;

    void resetFusionFlags();

public:
    Grille(int t = 4);

    void afficher() const;
    void ajouterTuileAleatoire();
    bool peutBouger() const;

    bool deplacerGauche();
    bool deplacerDroite();
    bool deplacerHaut();
    bool deplacerBas();

    bool victoire() const;
};

#endif
