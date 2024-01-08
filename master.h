/*prototypes de master.c*/

int analyse_arg(int nb, char** val, short* ordinateur, short* positionnement) ;

int jeu (int ennemi, int position);




struct profil_s {
    unsigned int nb_parties;
    unsigned int nb_victoires;
};

typedef struct profil_s profil;