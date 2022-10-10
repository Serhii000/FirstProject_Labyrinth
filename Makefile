CC=gcc
CFLAGS=-lncurses

SRCD=src/
SRC=$(addprefix $(SRCD), *.c)

OBJD=obj/
OBJ=$(addprefix $(OBJD), *.o)

EXE=labyrinth

objects:
	mkdir $(OBJD) 
	$(CC) $(SRC) $(CFLAGS) -c
	mv *.o $(OBJD)

	$(CC) main.c $(CFLAGS) -c

exe:
	$(CC) main.o $(OBJ) $(CFLAGS) -o $(EXE)

install: clean objects exe


clean:
	rm -rf $(OBJD) main.o


reinstall: clean install

delete: clean
	rm labyrinth
	