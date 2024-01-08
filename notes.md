Voir pour jouer contre ordi et taille tableau jeu variable éventuellement go oublier ca
Finir fonction affichage
améliorer transmission arguments en tableau aux affichages
optimiser
double tableau valeurs pour connaitre joueur 1 et joueur 2, check
règles de vérification à faire plus tard
tableaux multidimensionnels pour simplifier/complexifier ? : ```c int tableau[5][5]```, check
vérif positionnement bateau, vérif de sortie
faire en sorte que quand un bateau coule ca l'affiche quand j'aurai fini le reste et surtout les vérifs, c bon ?
utilisation fonctions pour placement bateaux et variables nb de bateaux ?, check
rempler printf affichate tableau par dire tableau ennemi ou le notre, check
ligne entree -> commencer à compter à partir de 1
génération aléatoire position bateau
makefile, check
do while verif placement bateaux

règles :
10*10 cases
```1*5 + 1*4 + 2*3 +1*2``` ce qui fait donc 17 pour une solution bourrine pour l'initialisation, amélioré

faire attention utiliser int(0) et pas char(0) dans ligne tableau

problèmes :
[] optimisation oubliée
[] bug relancer partie, fait
[] bug gestion des caractères dans jeu()

manipuler des tableaux sans pointeurs dans des fonctions parait extrêmement chelou

go surcharger la fonction verif lol
polymorphisme/surchage/typedef struct

voir installer et utiliser make sur windows -> installer cmake pour multisystème à voir
faire une fonction récursive parce que pourquoi pas

utilisation couleur dans fonction affichage selon type cases, multi plateforme a l'air compliqué

affichage sur des carrés plutot que sur des rectangles


inverser [colonne_entree] et [ligne_entree], c bon
chaque sous liste représente une ligne et non une colonne


branche pour options :
option 1 : --help/-h/-? affiche l'équivalent du readme
option 2 : choix du positionnement, aléatoire par défaut, ‐-manuel/-m --hasard/-h
option 3 : 1v1 or 1vsia (hasard striking ia avec verif cout pas déjà fait et probablement un jour indice de predictabilite des coups basés sur les coups deja effectues sinon random)
-ia/--ia -e/--ennemi

typedef struct var :
liste positions
hp probablement
en vie ou pas
pas

var bateaux en vie probablement plus tard et fonction s'appliquant aux typedzf struct pour vérifier leur vie plutot que parcours du bateau
bateau

tester cmake

dans affichage afficher pour soi les bateaux en vie et coulés ainsi que types
dans affichage pour ennemi afficher bateaux coulés et type

Afficher quand un bateau est coulé : probablement fonction d'affichage séparée 


possibilité de faire plusieurs ui.c avec différents languages vu que tt les printf sont à l'intérieur

menu pour choisir les options au début
modifier affichage points si bataille contre ia
fonction pour quitter : exit
remplacer return exit failure par exit(code) et définir des codes d'erreur / faire une analyse des code de retour des fonctions pour mettre des return exit_failure qui soient corrects

améliorer makefile
finir implémentation debug makefile avec -aux-info fichier pour liste des fonctions
ajouter ifnotdef dans header
faire refonte des header et du makefile en conséquent
implémenter système de profils basé sur du xml/json à déterminer