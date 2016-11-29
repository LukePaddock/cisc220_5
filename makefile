udll.o: udll.c udll.h
	gcc -Wall -c udll.c
main.o: main.c
	gcc -Wall -c main.c
udll: udll.o main.o
	gcc -Wall -o udll main.o udll.o
clean: udll
	rm udll.o main.o
