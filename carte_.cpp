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
			//Dans cette boucle verifier si la case est dans la carte
			if (estDansCarte(verif_pos))
			{
				//Verfifier si les cases verifiers sont des mines ou des riens estUneMine()
				if (m_cases[pos_ligne][pos_colonne].estUneMine())
				{
					//Incrementer compteur du nombre de mines adjacent si case = mine
					++m_cases[pos_ligne][pos_colonne];
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

bool Carte::essaieCase(Position e_pos)
{
	//Verifie si la case a deja ete ouverte
	int ligne = e_pos.ligne();
	int colonne = e_pos.colonne();

	if (m_cases[ligne][colonne].estOuverte())
	{
		return true;
	}
	else
	{
		//Sinon verifie si la case est une mine
		if (m_cases[ligne][colonne].estUneMine())
		{
			return false;
		}
		else
		{
			//Ouvrir les cases voisines jusqu'a une mine

			//Ouvrir les cases vertical vers le bas
			for (int i = ligne;i <= nbLignes();i++)
			{
				Position new_pos(ligne, colonne);
				if (m_cases[ligne][colonne].estUneMine()) {}
				else
				{
					ouvreCase(new_pos);
				}
			}

			//Ouvrir les cases vertical vers le haut
			for (int i = ligne;i >= 0;i--)
			{
				Position new_pos(ligne, colonne);
				if (m_cases[ligne][colonne].estUneMine()) {}
				else
				{
					ouvreCase(new_pos);
				}
			}

			//Ouvrir les cases horizontal vers la gauche
			for (int i = colonne;i >= 0;i--)
			{
				Position new_pos(ligne, colonne);
				if (m_cases[ligne][colonne].estUneMine()) {}
				else
				{
					ouvreCase(new_pos);
				}
			}

			//Ouvrir les cases horizontal vers la droite
			for (int i = colonne;i <= nbColonnes();i++)
			{
				Position new_pos(ligne, colonne);
				if (m_cases[ligne][colonne].estUneMine()) {}
				else
				{
					ouvreCase(new_pos);
				}
			}

			//Ouvrir les cases diagonal haut vers la gauche
			for (int i = colonne;i >= 0;i--)
			{
				for (int e = ligne;e <= nbLignes();e++)
				{
					Position new_pos(ligne, colonne);
					if (m_cases[ligne][colonne].estUneMine()) {}
					else
					{
						ouvreCase(new_pos);
					}
				}
			}

			//Ouvrir les cases diagonal haut vers la droite
			for (int i = colonne;i <= nbColonnes();i++)
			{
				for (int e = ligne;e <= nbLignes();e++)
				{
					Position new_pos(ligne, colonne);
					if (m_cases[ligne][colonne].estUneMine()) {}
					else
					{
						ouvreCase(new_pos);
					}
				}
			}

			//Ouvrir les cases diagonal bas vers la gauche
			for (int i = colonne;i >= 0;i--)
			{
				for (int e = ligne;e >= 0;e--)
				{
					Position new_pos(ligne, colonne);
					if (m_cases[ligne][colonne].estUneMine()) {}
					else
					{
						ouvreCase(new_pos);
					}
				}
			}

			//Ouvrir les cases diagonal bas vers la droite
			for (int i = colonne;i >= 0;i--)
			{
				for (int e = ligne;e <= nbLignes();e++)
				{
					Position new_pos(ligne, colonne);
					if (m_cases[ligne][colonne].estUneMine()) {}
					else
					{
						ouvreCase(new_pos);
					}
				}
			}
		}
	}

	//Refaire completement recursivement

	return true;
};

// Description: Methode qui calcule le nombre de mines adjacentes pour les cases libres de la carte
// post : pour chacune des cases qui ne contient pas une mine, on compte le nombre de mines adjacentes

void Carte::compteMinesAdjParCase()
{
	//for all the elements of the table call getNbMinesAdj and then change its value to that
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