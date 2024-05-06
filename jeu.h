/*prototypes de jeu.c : */

int demande_placement(char bateau1[10][10], char bateau2[10][10]);

int verif_libre(const char tableau[10][10], int valeur_d, int valeur_f, short orientation, int taille);

int bateau (char tableau[10][10], int taille, int aleatoire);

int initialisation (char tableau[10][10], int alea);

int verif (char tableau[10][10], int *statut);

