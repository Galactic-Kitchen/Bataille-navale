bataille_navale.exe : master.o jeu.o ui.o
	gcc -o bataille_navale.exe master.o jeu.o ui.o

jeu.o: jeu.c
	gcc -c -o jeu.o jeu.c

ui.o : ui.c
	gcc -c -o ui.o ui.c

master.o : master.c
	gcc -c -o master.o master.c