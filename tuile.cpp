#include "Tuile.h"

Tuile::Tuile(int v) : valeur(v), aFusionne(false) {}

int Tuile::getValeur() const {
    return valeur;
}

void Tuile::setValeur(int v) {
    valeur = v;
}

bool Tuile::asFusionne() const {
    return aFusionne;
}

void Tuile::setFusion(bool b) {
    aFusionne = b;
}

void Tuile::resetFusion() {
    aFusionne = false;
}
