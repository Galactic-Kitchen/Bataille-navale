CC = gcc
NAME = bataille_navale
FLAGS_ANSI = 
FLAGS_NAME = -o
FLAGS_OBJ = -c
FLAG_DEBUG = 
FLAG_LST_FCT = -aux-info $@_debug_info.txt 
NAME_DEBUG = debug_info.txt

${NAME}.exe : master.o jeu.o ui.o
	${CC} ${FLAG_DEBUG} ${FLAGS_ANSI} ${FLAGS_NAME} $@ $^

%.o : %.c %.h header.h
	${CC} ${FLAG_DEBUG} ${FLAGS_ANSI} ${FLAGS_OBJ} $<
	
run :
	./${NAME}.exe
	
rebuild : clean
	make

clean :  mrproper
	rm -f *.o
	rm -f *${NAME_DEBUG}

mrproper :
	rm -f ${NAME}*.exe

ansic : bataille_navale_h.h 
	make clean
ifeq ($(origin FLAGS_ANSI), undefined)
$(FLAG_DEBUG) = -ansi -pedantic
endif
	make

debug : bataille_navale_h.h 
	make clean
ifeq ($(origin FLAG_DEBUG), undefined)
$(FLAG_DEBUG) = -g
endif
	make