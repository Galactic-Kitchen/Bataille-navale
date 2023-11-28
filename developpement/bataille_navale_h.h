#ifndef BATEAU_NON_TOUCHE
#define BATEAU_NON_TOUCHE 'x'
#define BATEAU_TOUCHE 'H'
#define COUP_DANS_LEAU 'o'
#endif

#ifndef SEPARATEUR
#define SEPARATEUR '|'
#endif

#ifndef NOMBRE_PORTE_AVIONS
#define NOMBRE_PORTE_AVIONS 1
#define NOMBRE_CUIRASSES 1
#define NOMBRE_CROISEURS 2
#define NOMBRE_DESTROYERS 1
#endif

/*prototypes de jeu.c : */

int demande_placement(char bateau1[10][10], char bateau2[10][10]);

int bateau (char tableau[10][10], int taille, int aleatoire) ;

int initialisation (char tableau[10][10], int alea) ;

int verif (char tableau[10][10], int *statut);

/*prototypes de ui.c : */

int aide () ;

int print_victoire(int nb);

int print_changement_options(short ennemi, short placement);

int nouvelle_partie_question (char *sortie);

int affichage_scores (int c_p, int c_v);

int affichage (char tableau[10][10], char relation);