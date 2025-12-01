#ifndef TUILE_H
#define TUILE_H

class Tuile {
private:
    int valeur;
    bool aFusionne;

public:
    Tuile(int v = 0);

    int getValeur() const;
    void setValeur(int v);

    bool asFusionne() const;
    void setFusion(bool b);

    void resetFusion();
};

#endif
