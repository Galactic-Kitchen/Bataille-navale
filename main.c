#include <stdlib.h>
#include <stdio.h>
#define TIRET '-'
#define SEPARATEUR '|'

int main (void) {
   /* char colonne_entree, ligne_entree; dans fonction jeu pr optimiser */
    short taille_jeu=3; /* ca sera utilisé plus tard */
	char statut;
	int compteur_partie=0, compteur_victoire; /*compteur_partie - compteur_victoire = compteur joueur 2*/
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


int nouvelle_partie_question (sortie) {
	char reponse;
	printf("nouvelle partie ?\na : afficher les scores, y : lancer une nouvelle partie, q : quitter")
	reponse=getchar();
	while (reponse!='y' or reponse!='a' or reponse !='q') {
		printf("réessayer\n");
		reponse=getchar();
	}
	&sortie=reponse;
	return EXIT_SUCCESS;
}


int affichage_scores (c_p, c_v) {
	printf(" nombre de parties jouées, nombre de partie gagnées par joueur 1, nombre de parties gagnées par joueur 2\n %5d%5c %5d%5c%5d", c_p, SEPARATEUR, c_v, SEPARATEUR, c_p-c_v);
	return EXIT_SUCCESS;
}

int jeu (void) {
	int victoire;
	
	
	return victoire;



int affichage (tableau) {
    int i,k,t;
    for (i=0;i<Taille_jeu;i++) { //première ligne affichage tableau
        printf("\9c", 'a'+i);
    }
    for (k=0;k<Taille_jeu;k++) { //boucle séparation et cases
        for (t=0;t<Taille_jeu;t++) { //boucle séparateur
            printf("");
        }
    
    
    }

}