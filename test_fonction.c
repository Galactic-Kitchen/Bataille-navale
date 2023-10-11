#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'

#include <time.h>


int affichage (char tableau[10][10], char relation) { /*probablement un bug ici*/
    int l,c;
	/* affichage avec tableau 2 dimensions et joueur=num joueur et donc quoi afficher, a : ami, b : ennemie*/
	printf("%s",(relation=='a')?"\nAffichage de votre grille :\n":"Affichage du radar de la grille ennemie :\n");
	for (l=0;l<10;l++) {
		printf("%c\t %c ", 'a'+l, SEPARATEUR);
	}
	printf("\n--");
	for (l=0;l<10;l++) {
		printf("-------+");
	}
	printf("\n");
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
	else return EXIT_FAILURE;
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
	printf("%d k", presence_x);
	if (presence_x==0) {
		*statut=3;
	}
	return EXIT_SUCCESS;
}

int main (void) {
	char test[10][10]={'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'};
	char test1[10][10]={};
	int statut=5;
	//bateau(test1, 6);
	char ami='a';
	affichage(test,ami);
	/*verif(test, &statut);
	printf("%d", statut);*/
	return EXIT_SUCCESS;
}	