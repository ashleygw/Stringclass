# Macros ========================================



CC=g++

CFLAGS=-c -Wall -Wextra -Werror -ansi -pedantic



ERASE=rm

OBJECTS=Main.o sClass.o

EXE=sClass.out



# Targets ========================================

all : $(EXE)



$(EXE) : $(OBJECTS)

	$(CC) $(OBJECTS) -o $(EXE)



Main.o : Main.cpp sClass.h

	$(CC) $(CFLAGS) -c Main.cpp -o Main.o



sClass.o : sclass.cpp sClass.h

	$(CC) $(CFLAGS) -c sClass.cpp -o sClass.o



clean :

	$(ERASE) $(OBJECTS) $(EXE)