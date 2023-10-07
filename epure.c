#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'
/*a1 a2 a3 a4 a5 a6 a7 a8 a9 b0 b1 b2 b3 b4 b5 b6 b7*/

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


int jeu (void) {
	short i,relation;
	int victoire, statut=1;
	char colonne_entree, ligne_entree;
	char position1[10][10]={}; /* x: bateau présent non découvert, o : coup dans l'eau, 0 (et non '0') : absence de bateau, H : bateau touché découvert*/
	char position2[10][10]={};
	while (statut==1) {
		/* création position des bateaux*/
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 1 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=getchar()-'a';
            ligne_entree=getchar()-'0';
			getchar(); /*espace*/
			position1[colonne_entree][ligne_entree]='x';
		}
		printf("insérer la position des bateaux séparés par des espaces seulement du joueur 2 en une fois");
		for (i=0;i<17;i++) {
			colonne_entree=getchar()-'a';
			ligne_entree=getchar()-'0';
			getchar(); /*espace*/
			position2[colonne_entree][ligne_entree]='x';
		}
		statut=2;
	}
	while (statut==2) {
		printf("tour de joueur 1\n");
		relation='a';
		affichage(position1, relation);
		relation='b';
		affichage(position2, relation);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
		ligne_entree=getchar()-'0'; /* insérer vérif si tir déjà fait un jour*/
		getchar();/* récupère l'espace, marchera que sous linux*/
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
		/* fin tour joueur 1*/
		printf("tour de joueur 2\n");
		relation='a';
		affichage(position2, relation);
		relation='b';
		affichage(position1, relation);
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
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
        else if ((position1[colonne_entree][ligne_entree]=='o')||(position1[colonne_entree][ligne_entree]=='H')) {
			printf("T'as tiré à un endroit où t'avais déjà tiré...\n");
		}
		else {
			return EXIT_FAILURE;
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