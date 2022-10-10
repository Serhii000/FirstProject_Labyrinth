CC=gcc
CFLAGS=-lncurses
LDFLAGS=
SOURCES=main.c src/StartScreen.c src/menu.c src/menu_des.c src/menu_dev.c src/level_one.c src/endingscr.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=labyrinth

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(CFLAGS) -o $(EXECUTABLE)

