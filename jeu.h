#ifndef JEU_H
#define JEU_H

#include "Grille.h"

class Jeu {
private:
    Grille grille;
    bool fini;

public:
    Jeu();
    void bouclePrincipale();
};

#endif
