//
//  position.h
//

#ifndef POSITION_H
#define POSITION_H
// Fait par Oli
class Position {
private:
    int ligne;   // Représente la ligne de la position
    int colonne; // Représente la colonne de la position

public:
    // Constructeur par défaut
    Position() {
        ligne = 0;
        colonne = 0;
    }

    //initilisation du constructeur
    Position(int l, int c) {
        ligne = l;   // Affecte la valeur de l à la ligne
        colonne = c; // Affecte la valeur de c à la colonne
    }
     //accesseurs
    int getLigne() {
        return ligne;
    }
    int getColonne() {
        return colonne;
    }

    friend std::istream& operator>> (std::istream& in, Position& position);
    friend std::ostream& operator<< (std::ostream& out, Position& position);

};

#endif /* Position_h */
