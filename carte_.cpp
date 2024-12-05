// fichier : carte_.cpp
// auteur.es : Olivier Germain, Kakou Boris sosthene
// date : 2024
// modifications :
// description : Ce fichier contient la definition des methodes A IMPLEMENTER de la classe Carte d'un jeu de demineur

#include "carte.h"
#include "utilitaires.h"

#include <iomanip>
#include <cassert>
#include <stdio.h>

// Description: Methode qui calcule le nombre de mines adjacentes a une case
// param[E] Position de la case
// retour : nombre de mines adjacentes a la case
// post : on compte le nombre de mines adjacentes a la case (entre 0 et 8)

Compteur Carte::getNbMinesAdjacentes(Position e_pos)
{
	int ligne = e_pos.ligne() - 1;
	int colonne = e_pos.colonne() - 1;

	for (int pos_ligne = 0;pos_ligne < 2;pos_ligne++)
	{
		for (int pos_colonne = 0;pos_colonne < 2;pos_colonne++)
		{
			Position verif_pos(pos_ligne, pos_colonne);
			if (estDansCarte(verif_pos)) // verifie si case est valide
			{
				if (m_cases[pos_ligne][pos_colonne].estUneMine()) // Verifie si les cases adjacentes sont des mines
				{
					++m_cases[pos_ligne][pos_colonne]; // compteur de mine adjacente
				}
			}
		}
	}

	return 0;
}

// Description: Methode qui essaie d'ouvrir une case
// param[E] Position de la case
// retour : booleen - vrai si ce n'est pas une mine, faux sinon
// post : si la case a deja ete ouverte, ce n'est pas une mine -> retourne vrai, si la case n'est pas une mine, les cases voisines doivent etre ouvertes jusqu'a une prochaine mine

// Fonction pour essayer d'ouvrir une case donnée et ses voisines si nécessaire
// Fonction pour essayer d'ouvrir une case donnée et ses voisines si nécessaire
bool Carte::essaieCase(Position e_pos)
{
	if (m_cases[e_pos.ligne()][e_pos.colonne()].estOuverte()) //si est deja ouverte
	{
		return true;
	}

	if (m_cases[e_pos.ligne()][e_pos.colonne()].estUneMine()) // si est une mine
	{
		return false;
	}

	ouvreCase(e_pos); // si pas deja ouverte ET pas une mine --> ouvre la case

	const int directions[8][2] = {     // liste des deplacements (le 8 correspond au nb de deplacement et le 2 puisque tableau de 2 dimensions)
		{-1, -1}, // Haut Gauche
		{-1, 0},  // Haut
		{-1, 1},  // Haut Droite
		{0, -1},  // Gauche
		{0, 1},   // Droite
		{1, -1},  // Bas Gauche
		{1, 0},   // Bas
		{1, 1}    // Bas Droite
	};

	for (int i = 0; i < 8; ++i)
	{
		int nouvelleLigne = e_pos.ligne() + directions[i][0]; // Prend le premier chiffre de chaque vecteur (axe des X)
		int nouvelleColonne = e_pos.colonne() + directions[i][1]; // prend le second chiffre de chaque vecteur (axe Y)
		Position nouvellePos(nouvelleLigne, nouvelleColonne); // objet positions (pour la nouvelle case)

		if (estDansCarte(nouvellePos) && !m_cases[nouvelleLigne][nouvelleColonne].estOuverte()) // si case valide ET non ouverte.
		{
			if (!m_cases[nouvelleLigne][nouvelleColonne].estUneMine()) // si n'est pas une mine
			{
				ouvreCase(nouvellePos); // ouvre la case
				essaieCase(nouvellePos); // appel recursif pour propager
			}
		}
	}
	return true;
}

// Description: Methode qui calcule le nombre de mines adjacentes pour les cases libres de la carte
// post : pour chacune des cases qui ne contient pas une mine, on compte le nombre de mines adjacentes

void Carte::compteMinesAdjParCase()
{

	for (int l = 0;l <= nbLignes();l++)
	{
		for (int c = 0;c <= nbColonnes();c++)
		{
			if (m_cases[l][c].estOuverte())
			{
				Position pos_courante;
				int ligne = pos_courante.ligne();
				int colonne = pos_courante.colonne();
				getNbMinesAdjacentes(pos_courante);
			}
		}
	}
}