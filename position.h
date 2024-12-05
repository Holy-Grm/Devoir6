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
	int _ligne;   // Repr�sente la ligne de la position
	int _colonne; // Repr�sente la colonne de la position

public:
	// Constructeur par d�faut
	Position() {
		_ligne = 0;
		_colonne = 0;
	}

	//initilisation du constructeur
	Position(int l, int c) {
		_ligne = l;   // Affecte la valeur de l � la ligne
		_colonne = c; // Affecte la valeur de c � la colonne
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
