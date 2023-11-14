#include <stdlib.h>
#include <stdio.h>

#include "bataille_navale_h.h"

int aide () {
	printf("\tJeu de Bataille Navale.\n");
	printf("Jeu de bataille navale écrit en C.\n");
	printf("Différents options sont disponibles :\n");
	printf("-?/--help/-h : affiche l'aide\n");
	printf("-m/--manuel & -h/--hasard : choix du positionnement des bateaux : aléatoire ou manuel (pas encore implémenté)\n");
	printf("-i/--ia & -e/--ennemi : permet de choisir de jouer contre un algorithme ou contre un ami (amitié optionnelle)(pas encore implémenté)\n");
	return EXIT_SUCCESS;
}
int print_victoire(int nb) {
	printf("Le joueur %d a gagné cette partie\n",nb);
	return EXIT_SUCCESS;
}

int print_changement_options(short ennemi, short placement) {
	printf("les options actuelles sont :\n");
	printf("Placement des bateaux : %s\n", (placement==1)?"Placement manuel":"Placement automatique aléatoire");
	printf("Ennemi affronté %s\n", (ennemi==1)?"Affronter l'ordinateur":"Affronter un ami (amitié optionelle)");
	printf("Entrer e en minuscule pour basculer l'ordinateur, entrer p pour basculer le placement, entrer 3 caractères en tout impérativement");
	return EXIT_SUCCESS;
}

int nouvelle_partie_question (char *sortie) {
	char reponse;
	printf("nouvelle partie ?\na : afficher les scores, y : lancer une nouvelle partie, q : quitter, o : changer les options\n");
	reponse=getchar();
	getchar();
	while ((reponse!='y') && (reponse!='a') && (reponse !='q') && (reponse!='o')) { /*bug quelque part / reformatage à faire*/
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
	printf("\n%s\n",(relation=='a')?"Affichage de votre grille :":"Affichage du radar de la grille ennemie :");
	printf(" \t%c", SEPARATEUR);
	for (l=0;l<10;l++) {
		printf(" %c\t%c", 'a'+l, SEPARATEUR);
	}
	printf("\n");
	for (l=0;l<=10;l++) {
		printf("+-------");
	}
	printf("+\n");
    for (l=0;l<10;l++) {
		printf("%d\t%c", l+1, SEPARATEUR);
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
			printf("%c ", SEPARATEUR);
		}
		printf("\n");
		for (c=0;c<10;c++) {
			printf("+-------");
		}
		printf("+-------+\n");
	}
	return EXIT_SUCCESS;
}