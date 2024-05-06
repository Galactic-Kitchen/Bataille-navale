#include <stdlib.h>
#include <stdio.h>

#include "header.h"


#include <time.h>



int demande_placement(char bateau1[10][10], char bateau2[10][10]) {
	short i, temp1, temp2;
	printf("Veuillez entrer successivement la position des bateaux");
	for (i=0;i<10;i++) {
		temp1=getchar()-'a';
		scanf("%d", &temp2);
		getchar();
		temp2--;
		bateau1[temp1][temp2]=BATEAU_NON_TOUCHE;
		temp1=getchar()-'a';
		scanf("%d", &temp2);
		getchar();
		temp2--;
		bateau2[temp1][temp2]=BATEAU_NON_TOUCHE;
	}
	return EXIT_SUCCESS;
}
int verif_libre(const char tableau[10][10], int valeur_d, int valeur_f, short orientation, int taille) {
	short libre=0;
	short i;
	for (i=0;i<taille;i++) {
		if (tableau[valeur_d][valeur_f]!=0) {
			libre++;
		}
		orientation==1? valeur_d++ : valeur_f++;
	}
	return libre==0;
}
int bateau (char tableau[10][10], int taille, int aleatoire) {
	/*fonction qui place les bateaux aléatoirement, pas oublier de verif pas de superposition et dépassement tableaux, pas dépassement du tableau vérification inhérente*/
	int valeur_depart1, valeur_depart2;
	short i, orientation;
	short sortie;
	do {
	sortie=0;
	srand(time(NULL)+aleatoire);
	valeur_depart1=rand()%(10-taille);
    srand(time(NULL)+1+aleatoire);
	valeur_depart2=(rand()%10)-1;
    srand(time(NULL)+2+aleatoire);
	orientation=(rand()%2);
	if (verif_libre(tableau, valeur_depart2, valeur_depart1, orientation, taille)) {
		if (orientation==1) {
			for (i = 0; i < taille; i++) {
				tableau [valeur_depart2][valeur_depart1+i]=BATEAU_NON_TOUCHE; /*vers la droite*/
			}
		} else {
			for (i = 0; i < taille; i++) {
				tableau [valeur_depart1+i][valeur_depart2]=BATEAU_NON_TOUCHE; /*vers le bas*/
			}
		}
	} else {
		sortie++;
	}
	} while(sortie!=0);
	return EXIT_SUCCESS;
}


int initialisation (char tableau[10][10], int alea) { /* fonction qui gère le placement des bateaux aléatoirement*/
	short i;
	short taille_porte_avions = 5;
	short taille_cuirasses = 4;
	short taille_croiseurs = 3;
	short taille_destroyers = 2;
	for (i=0;i<NOMBRE_PORTE_AVIONS;i++) {
		bateau(tableau, taille_porte_avions, (time(NULL)%42)*alea);
	}
	for (i=0;i<NOMBRE_CUIRASSES;i++) {
		bateau(tableau, taille_cuirasses, (time(NULL)%69)*alea);
	}
	for (i=0;i<NOMBRE_CROISEURS;i++) {
		bateau(tableau, taille_croiseurs, (time(NULL)%420)*alea);
	}
	for (i=0;i<NOMBRE_DESTROYERS;i++) {
		bateau(tableau, taille_destroyers, (time(NULL)%666)*alea);
	}
	return EXIT_SUCCESS;
}

int verif (char tableau[10][10], int *statut) {
	short presence_x=0, i, j;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			if (tableau[i][j]==BATEAU_NON_TOUCHE) {
				presence_x =1;
			}
		}
	}
	if (presence_x==0) {
		*statut=3;
	}
	return EXIT_SUCCESS;
}