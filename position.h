//
//  position.h
//

#include <iostream>
#ifndef POSITION_H
#define POSITION_H
using namespace std;

// Fait par Oli
class Position {
private:
    int ligne;   // Repr�sente la ligne de la position
    int colonne; // Repr�sente la colonne de la position

public:
    // Constructeur par d�faut
    Position() {
        ligne = 0;
        colonne = 0;
    }

    //initilisation du constructeur
    Position(int l, int c) {
        ligne = l;   // Affecte la valeur de l � la ligne
        colonne = c; // Affecte la valeur de c � la colonne
    }
     //accesseurs
    int getLigne() {
        return ligne;
    }
    int getColonne() {
        return colonne;
    }

    friend istream& operator>> (istream& in, Position& position);
    friend ostream& operator<< (ostream& out, Position& position);

};

#endif /* Position_h */
