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
	int _ligne;   // Représente la ligne de la position
	int _colonne; // Représente la colonne de la position

public:
	// Constructeur par défaut
	Position() {
		_ligne = 0;
		_colonne = 0;
	}

	//initilisation du constructeur
	Position(int l, int c) {
		_ligne = l;   // Affecte la valeur de l à la ligne
		_colonne = c; // Affecte la valeur de c à la colonne
	}
	//accesseurs
	int ligne() const {
		return _ligne;
	}
	int colonne() const {
		return _colonne;
	}

	friend istream& operator>>(istream& in, Position& position);
	friend ostream& operator<<(ostream& out, const Position& position);
};

#endif /* Position_h */
