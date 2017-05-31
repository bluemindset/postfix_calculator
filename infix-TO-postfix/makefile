
CC = gcc
CFLAGS  = -g -Wall


default: infix_to_postfix

infix_to_postfix: infix_to_postfix.o
	$(CC) $(CFLAGS) -o infix_to_postfix infix_to_postfix.o

infix_to_postfix.o:  infix_to_postfix.c 
	$(CC) $(CFLAGS) -c infix_to_postfix.c 
clean: 
	$(RM) *.exe *.o *~