#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'

int affichage (char tableau[10][10], char relation) { /*probablement un bug ici*/
	/*short Taille_jeu=3;*/
    int l,c,t;
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

int main (void) {
	char test[10][10]={'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'};
	char ami='a';
	affichage(test,ami);
	return EXIT_SUCCESS;
}
	