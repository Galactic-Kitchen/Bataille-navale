#include <stdlib.h>
#include <stdio.h>

#define NOMBRE_PORTE_AVIONS 1
#define NOMBRE_CUIRASSES 1
#define NOMBRE_CROISEURS 2
#define NOMBRE_DESTROYERS 1

#include <time.h>

int bateau (char tableau[10][10], int taille, int aleatoire) {
	/*fonction qui place les bateaux aléatoirement, pas oublier de verif pas de superposition et dépassement tableaux, pas dépassement du tableau vérification inhérente*/
	int valeur_depart1, valeur_depart2;
	short i, orientation;
	srand(time(NULL)+aleatoire);
	valeur_depart1=rand()%(10-taille);
    srand(time(NULL)+1+aleatoire);
	valeur_depart2=(rand()%10)-1;
    srand(time(NULL)+2+aleatoire);
	orientation=(rand()%2);
	if (orientation==1) {
		for (i = 0; i < taille; i++) {
			tableau [valeur_depart2][valeur_depart1+i]='x'; /*vers le bas*/
		}
		}
	else {
		for (i = 0; i < taille; i++) {
			tableau [valeur_depart1+i][valeur_depart2]='x'; /*vers le haut*/
		}
		}
	return EXIT_SUCCESS;
}


int initialisation (char tableau[10][10], int alea) { // fonction qui gère le placement des bateaux aléatoirement
	short i;
	for (i=0;i<NOMBRE_PORTE_AVIONS;i++) {
		bateau(tableau, 5, (time(NULL)%42)*alea);
	}
	for (i=0;i<NOMBRE_CUIRASSES;i++) {
		bateau(tableau, 4, (time(NULL)%69)*alea);
	}
	for (i=0;i<NOMBRE_CROISEURS;i++) {
		bateau(tableau, 3, (time(NULL)%420)*alea);
	}
	for (i=0;i<NOMBRE_DESTROYERS;i++) {
		bateau(tableau, 2, (time(NULL)%666)*alea);
	}
	return EXIT_SUCCESS;
}

int verif (char tableau[10][10], int *statut) {
	short presence_x=0, i, j;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			if (tableau[i][j]=='x') {
				presence_x =1;
			}
		}
	}
	if (presence_x==0) {
		*statut=3;
	}
	return EXIT_SUCCESS;
}