#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'
/*a1 a2 a3 a4 a5 a6 a7 a8 a9 b0 b1 b2 b3 b4 b5 b6 b7*/
#define NOMBRE_PORTE_AVIONS 1
#define NOMBRE_CUIRASSES 1
#define NOMBRE_CROISEURS 2
#define NOMBRE_DESTROYERS 1
#include <time.h>

int affichage (char tableau[10][10], char relation) { /*probablement un bug ici*/
    int l,c;
	/* affichage avec tableau 2 dimensions et joueur=num joueur et donc quoi afficher, a : ami, b : ennemie*/
	printf("%s",(relation=='a')?"\nAffichage de votre grille :\n":"Affichage du radar de la grille ennemie :\n");
    for (l=0;l<10;l++) {
		for (c=0;c<10;c++) {
			if (tableau[l][c]=='x') {
				printf("%c\t",(relation=='a')?'x':' ');
			}
			else if (tableau[l][c]==0) {
				printf(" \t");
			}
			else if (tableau[l][c]=='H') {
				printf("H\t");
			}
			else if  (tableau[l][c]=='o') {
				printf("O\t");
			}
			printf(" %c ", SEPARATEUR);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

int bateau (char tableau[10][10], int taille, int aleatoire) {
	//fonction qui place les bateaux aléatoirement, pas oublier de verif pas de superposition et dépassement tableaux
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

int jeu (void) {
	short i,relation;
	int victoire=0, statut=1;
	char colonne_entree, ligne_entree;
	char position1[10][10]={}; /* x: bateau présent non découvert, o : coup dans l'eau, 0 (et non '0') : absence de bateau, H : bateau touché découvert*/
	char position2[10][10]={};
	/*while (statut==1) {
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 1 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=getchar()-'a';
            ligne_entree=getchar()-'0';
			getchar();
			position1[colonne_entree][ligne_entree]='x';
		}
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 2 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=getchar()-'a';
			ligne_entree=getchar()-'0';
			getchar();
			position2[colonne_entree][ligne_entree]='x';
		}
		statut=2;
	}*/
    initialisation(position1, 5);
    initialisation(position2, 7);
    //statut=2;
    affichage(position1, 'a');
    affichage(position2, 'a');
	while (statut==2) {
		printf("tour de joueur 1\n");
		relation='a';
		affichage(position1, relation);
		relation='b';
		affichage(position2, relation);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
		ligne_entree=getchar()-'0'; 
		getchar();
		printf("Tir en a : %c b : %d\n", colonne_entree+'a', ligne_entree);
		if (position2[colonne_entree][ligne_entree]=='x') {
			printf("Touché !\n");
			position2[colonne_entree][ligne_entree]='H';
		}
		else if (position2[colonne_entree][ligne_entree]==0) {
			printf("Raté !\n");
			position2[colonne_entree][ligne_entree]='o';
		}
        else if ((position1[colonne_entree][ligne_entree]=='o')||(position1[colonne_entree][ligne_entree]=='H')) {
		printf("T'as tiré à un endroit où t'avais déjà tiré...\n");
        }
		else {
			printf("c %d, e %d, k %d", colonne_entree, ligne_entree, position2[colonne_entree][ligne_entree]); return EXIT_FAILURE;
		}
		printf("tour de joueur 2\n");
		relation='a';
		affichage(position2, relation);
		relation='b';
		affichage(position1, relation);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
		ligne_entree=getchar()-'0'; 
		getchar();
		printf("Tir en %c%c\n", colonne_entree, ligne_entree);
		if (position1[colonne_entree][ligne_entree]=='x') {
			printf("Touché !\n");
			position1[colonne_entree][ligne_entree]='H';
		}
		else if (position1[colonne_entree][ligne_entree]==0) {
			printf("Raté !\n");
			position1[colonne_entree][ligne_entree]='o';
		}
        else if ((position1[colonne_entree][ligne_entree]=='o')||(position1[colonne_entree][ligne_entree]=='H')) {
			printf("T'as tiré à un endroit où t'avais déjà tiré...\n");
		}
		else {
			return EXIT_FAILURE;
		}
		verif(position2, &statut);
		i=statut;
		verif(position1, &statut);
		if (statut==3) {
			if (i==3) {
				victoire++;
				printf("Le joueur 1 a gagné cette partie\n");
			}
			else {
				printf("Le joueur 2 a gagné cette partie\n");
			}
		}
	}
		
	return victoire;
	}

int main (void) {
	int compteur_victoire=0; /*compteur_partie - compteur_victoire = compteur joueur 2*/
	compteur_victoire+=jeu();
    return EXIT_SUCCESS;
}