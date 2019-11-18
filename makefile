ifeq ($(DEBUG), yes)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	$(CC) -o program main.c

run: 
	./program

clean:
	rm *.o
	rm *~

memtest:
	valgrind --leak-check=yes ./program
