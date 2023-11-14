#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bataille_navale_h.h"

int analyse_arg(int nb, char** val, short* ordinateur, short* positionnement) {
	short i;
	if (nb==1) {
		return 0; /*pas besoin de parcourir les arguments s'il y en a pas*/
	}
	for (i = 1; i < nb; i++) {
		if (strcmp("--manuel", val[i]) == 0 || strcmp("-m", val[i])==0) {
			*positionnement = 1;
		}
		else if (strcmp("--ia", val[i]) == 0 || strcmp("-ia", val[i])==0) {
			*ordinateur = 1;
		}
		else if (strcmp("-h", val[i]) == 0 || strcmp("-?", val[i])==0) {
			aide();
		}
	}
	return EXIT_SUCCESS;
}

void quitter (void) {
	exit(EXIT_SUCCESS);
}

int changement_options (short *ennemi, short *placement ) {
	print_changement_options(*ennemi, *placement);
	if (getchar()=='e') {
		*ennemi=(*ennemi==0)?1:0;
		if (getchar()=='p') {
			*placement=(*placement==0)?1:0;
		}	
	}
	getchar();
	return EXIT_SUCCESS;
}

int jeu (int ennemi, int position) {
	short i;
	int victoire=0, statut=0;
	char colonne_entree, ligne_entree;
	char position1[10][10]={}; /* x: bateau présent non découvert, o : coup dans l'eau, 0 (et non '0') : absence de bateau, H : bateau touché découvert, voir les define au debut du fichier pour vérifier que c'est à jour*/
	char position2[10][10]={};
	if (position==0) {
		initialisation(position1, 5);
    	initialisation(position2, 7);
	}
	else {
		demande_placement(position1, position2);
	}
	statut=2;
	while (statut==2) {
		printf("Tour de joueur 1\n");
		affichage(position1, 'a');
		affichage(position2, 'b');
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
		ligne_entree=getchar()-'0'; /* insérer vérif si tir déjà fait un jour*/
		getchar();/* récupère l'espace, marchera que sous linux*/
		printf("Tir en a : %c b : %d\n", colonne_entree+'a', ligne_entree);
		if (position2[ligne_entree][colonne_entree]==BATEAU_NON_TOUCHE) {
			printf("Touché !\n");
			position2[ligne_entree][colonne_entree]=BATEAU_TOUCHE;
		}
		else if (position2[ligne_entree][colonne_entree]==0) {
			printf("Raté !\n");
			position2[ligne_entree][colonne_entree]=COUP_DANS_LEAU;
		}
        else if ((position1[ligne_entree][colonne_entree]==COUP_DANS_LEAU)||(position1[ligne_entree][colonne_entree]==BATEAU_TOUCHE)) {
		printf("T'as tiré à un endroit où t'avais déjà tiré...\n");
        }
		else {
			printf("c %d, e %d, k %d", colonne_entree, ligne_entree, position2[ligne_entree][colonne_entree]); return EXIT_FAILURE;
		}
		/* fin tour joueur 1*/
		printf("Tour de joueur 2\n");
		affichage(position2, 'a');
		affichage(position1, 'b');
		printf("Entrer la colonne et la ligne du tir à effectuer\n");
		colonne_entree=getchar()-'a';
		ligne_entree=getchar()-'0'; /* insérer vérif si tir déjà fait un jour pr l'en empêcher peut-être*/
		getchar();/* récupère l'espace, marchera que sous linux, ou sur windows jsp*/
		printf("Tir en %c%c\n", colonne_entree, ligne_entree);
		if (position1[ligne_entree][colonne_entree]==BATEAU_NON_TOUCHE) {
			printf("Touché !\n");
			position1[ligne_entree][colonne_entree]=BATEAU_TOUCHE;
		}
		else if (position1[ligne_entree][colonne_entree]==0) {
			printf("Raté !\n");
			position1[ligne_entree][colonne_entree]=COUP_DANS_LEAU;
		}
        else if ((position1[ligne_entree][colonne_entree]==COUP_DANS_LEAU)||(position1[ligne_entree][colonne_entree]==BATEAU_TOUCHE)) {
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
				print_victoire(1);
			}
			else {
				print_victoire(2);
			}
		}
		/*fin verif fin de partie*/
	}
		
	return victoire;
	}


int main (int argc, char** argv) {
   /* char colonne_entree, ligne_entree; dans fonction jeu pr optimiser */
	char statut;
	short ordi=0, position_manuelle=0;
	int compteur_partie=0, compteur_victoire=0; /*compteur_partie - compteur_victoire = compteur joueur 2*/
	analyse_arg(argc, argv, &ordi, &position_manuelle);
	nouvelle_partie_question(&statut); /*lancement programme*/
	for (;statut!='\0';) {
		if (statut=='a') {
			affichage_scores(compteur_partie, compteur_victoire);
			
		}
		else if (statut=='q') {
			quitter();
		}
		else if (statut=='o') {
			changement_options(&ordi, &position_manuelle);
		}
		else if (statut=='y') {
			compteur_partie++;
			compteur_victoire+=jeu(ordi, position_manuelle);
		}
		nouvelle_partie_question(&statut);
	}
    return EXIT_SUCCESS;
}