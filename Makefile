# Makefile for the GNU C compiler

FILE_BTREE	=	src/Btree.c

FILE_MAIN	=	src/main.c

BIN			=	bin/

COMPILE		=	gcc

all:
	echo "Compiling..."
	$(COMPILE) -o $(BIN)Btree.o $(FILE_BTREE)
	$(COMPILE) $(BIN)Btree.o $(FILE_MAIN) -o $(BIN)Exe
	echo "Done"