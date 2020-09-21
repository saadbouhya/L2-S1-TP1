c=gcc
op=-Wall -Wextra

all :  pile.o test_pile.o permut.o  epilogue.c 	
	$(c) $(op)   pile.o test_pile.o permut.o  epilogue.c -o epilogue
pile.o : pile.c pile.h
	$(c) $(op) -c pile.c	
permut.o : permut.c permut.h 
	$(c) $(op) -c permut.c
test_pile.o : test_pile.c test_pile.h
	$(c) $(op) -c test_pile.c

