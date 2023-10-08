bataille_navale.exe : master.o jeu.o ui.o
	gcc -o bataille_navale.exe master.o jeu.o ui.o

jeu.o: jeu.c
	gcc -o jeu.c

ui.o : ui.c
	gcc -o ui.c

master.o : master.c
	gcc -o master.c