#include <stdlib.h>
#include <stdio.h>
#define SEPARATEUR '|'

int jeu (void) {
	short i,relation;
	int victoire=0, statut=0;
	char colonne_entree, ligne_entree;
	char position1[10][10]={}; /* x: bateau présent non découvert, o : coup dans l'eau, 0 (et non '0') : absence de bateau, H : bateau touché découvert*/
	char position2[10][10]={};
	
	initialisation(position1, 5);
    initialisation(position2, 7);
	statut=2;
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
		/*fin verif fin de partie*/
	}
		
	return victoire;
	}


int main (void) {
   /* char colonne_entree, ligne_entree; dans fonction jeu pr optimiser */
    short taille_jeu=3; /* ca sera utilisé plus tard */
	char statut;
	int compteur_partie=0, compteur_victoire=0; /*compteur_partie - compteur_victoire = compteur joueur 2*/
	nouvelle_partie_question(&statut); /*lancement programme*/
	for (;statut!='q';) {
		if (statut=='a') {
			affichage_scores(compteur_partie, compteur_victoire);
			nouvelle_partie_question(&statut);
		}
		else {
		compteur_partie++;
		compteur_victoire+=jeu();
		nouvelle_partie_question(&statut);
		}
	}
    return EXIT_SUCCESS;
}