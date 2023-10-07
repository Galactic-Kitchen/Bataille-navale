#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'

int transformation(char colonne) { /* à refaire car c moche*/
	if (colonne=='a') { return 0; }
	else if (colonne=='b') { return 1; }
	else if (colonne=='c') { return 2; }
	else if (colonne=='d') { return 3; }
	else if (colonne=='e') { return 4; }
	else if (colonne=='f') { return 5; }
	else if (colonne=='g') { return 6; }
	else if (colonne=='h') { return 7; }
	else if (colonne=='i') { return 8; }
	else if (colonne=='j') { return 9; }
	else {printf("erreur fonction transformation, %c", colonne); return EXIT_FAILURE;}
}

int affichage (char tableau[10][10], char relation) { /*probablement un bug ici*/
    int l,c;
	/* affichage avec tableau 2 dimensions et joueur=num joueur et donc quoi afficher, a : ami, b : ennemie*/
	printf("affichage tableau \n");
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


int jeu (void) {
	short i,j;
	int victoire, statut=1;
	char colonne_entree, ligne_entree;
	char position1[10][10]; /* x: bateau présent non découvert, o : coup dans l'eau, 0 (et non '0') : absence de bateau, H : bateau touché découvert*/
	char position2[10][10];
	while (statut==1) {
		/* création position des bateaux*/
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 1 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=transformation(getchar());
			ligne_entree=getchar();
			getchar(); /*espace*/
			position1[colonne_entree][ligne_entree-'0']='x';
		}
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 2 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=transformation(getchar());
			ligne_entree=getchar();
			getchar(); /*espace*/
			position2[colonne_entree][ligne_entree-'0']='x';
		}
		statut=2;
	}
	while (statut==2) {
		printf("tour de joueur 1\n");
		j='a';
		affichage(position1, j);
		j='b';
		affichage(position2, j);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=transformation(getchar());
		ligne_entree=getchar()-'0'; /* insérer vérif si tir déjà fait un jour*/
		getchar();/* récupère l'espace, marchera que sous linux*/
		getchar();/*now works under windows*/
		printf("tir en a : %c b : %c\n", colonne_entree, ligne_entree);
		if (position2[colonne_entree][ligne_entree]=='x') {
			printf("Touché !\n");
			position2[colonne_entree][ligne_entree]='H';
		}
		else if (position2[colonne_entree][ligne_entree]==0) {
			printf("Raté !\n");
			position2[colonne_entree][ligne_entree]='o';
		}
		else {
			printf("c %c, e %c", colonne_entree, ligne_entree); return EXIT_FAILURE;
		}
		/* fin tour joueur 1*/
		printf("tour de joueur 2\n");
		j='a';
		affichage(position2, j);
		j='b';
		affichage(position1, j);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=transformation(getchar());
		ligne_entree=getchar()-'0'; /* insérer vérif si tir déjà fait un jour*/
		getchar();/* récupère l'espace, marchera que sous linux, ou sur windows jsp*/
		printf("Tir en %c%c\n", colonne_entree, ligne_entree);
		if (position1[colonne_entree][ligne_entree]=='x') {
			printf("Touché !\n");
			position1[colonne_entree][ligne_entree]='H';
		}
		else if (position1[colonne_entree][ligne_entree]==0) {
			printf("Raté !\n");
			position1[colonne_entree][ligne_entree]='o';
		}
		else {
			return EXIT_FAILURE; /*plante si on tire sur un bateau déjà touché*/
		}
		/* fin tour joueur 2*/
	}
		
	return victoire;
	}

int main (void) {
	int compteur_victoire=0; /*compteur_partie - compteur_victoire = compteur joueur 2*/
	compteur_victoire+=jeu();
    return EXIT_SUCCESS;
}