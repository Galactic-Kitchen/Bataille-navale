CC = gcc
NAME = bataille_navale
FLAGS_ANSI = 
FLAGS_NAME = -o
FLAGS_OBJ = -c
FLAG_DEBUG = 
FLAG_LST_FCT = -aux-info $@_debug_info.txt 
NAME_DEBUG = debug_info.txt

${NAME}.exe : master.o jeu.o ui.o bataille_navale_h.h
	${CC} ${FLAG_DEBUG} ${FLAGS_ANSI} ${FLAGS_NAME} $@ $^

#jeu.o: jeu.c
	
#ui.o : ui.c
	
#master.o : master.c
%.o : %.c
	${CC} ${FLAG_DEBUG} ${FLAGS_ANSI} ${FLAGS_NAME} $@ $^
	
run :
	./${NAME}.exe
	
rebuild : clean
	make

clean :  mrproper
	rm -f *.o
	rm -f *${NAME_DEBUG}

mrproper :
	rm -f ${NAME}*.exe

ansic : bataille_navale_h.h #master_ansi.o jeu_ansi.o ui_ansi.o
	make clean
	FLAGS_ANSI = -ansi -pedantic
	make

debug : bataille_navale_h.h #master_debug.o jeu_debug.o ui_debug.o
	make clean
#	#$(FLAG_DEBUG) = -g
ifeq ($(origin FLAG_DEBUG), undefined)
$(FLAG_DEBUG) = -g
endif
	make
#	#${CC} ${FLAG_DEBUG} ${FLAGS_ANSI} ${FLAGS_NAME} ${NAME}_d.exe $^

#%_ansi.o: jeu.c
#	${CC} ${FLAGS_OBJ} ${FLAGS_ANSI} ${FLAGS_NAME} $@ $<

#%_debug.o : %.c
#	${CC} ${FLAGS_OBJ} ${FLAG_DEBUG} ${FLAGS_NAME} $@ $<