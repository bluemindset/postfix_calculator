
CC = gcc
CFLAGS  = -g -Wall


default: postfix_calc

postfix_calc: postfix_calc.o
	$(CC) $(CFLAGS) -o postfix_calc postfix_calc.o

postfix_calc.o:  postfix_calc.c 
	$(CC) $(CFLAGS) -c postfix_calc.c 
clean: 
	$(RM) *.exe *.o *~