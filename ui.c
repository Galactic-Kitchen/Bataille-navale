#include <stdlib.h>
#include <stdio.h>
#define SEPARATEUR '|'

int nouvelle_partie_question (char *sortie) {
	char reponse;
	printf("nouvelle partie ?\na : afficher les scores, y : lancer une nouvelle partie, q : quitter\n");
	reponse=getchar();
	getchar();
	while ((reponse!='y') && (reponse!='a') && (reponse !='q')) { /*bug quelque part / reformatage à faire*/
		printf("réessayer\n");
		reponse=getchar();
		getchar();
	}
	*sortie=reponse;
	return EXIT_SUCCESS;
}

int affichage_scores (int c_p, int c_v) {
	printf("nombre de parties jouées, nombre de partie gagnées par joueur 1, nombre de parties gagnées par joueur 2\n %8d %8c %8d %8c %8d \n", c_p, SEPARATEUR, c_v, SEPARATEUR, c_p-c_v); /* c'est pas joli */
	return EXIT_SUCCESS;
}


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