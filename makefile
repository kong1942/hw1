all:main.c sort.o
	gcc main.c sort.o -o main

sort.o: sort.h sort.c
	gcc -c sort.c -o sort.o

clean:
	rm -f sort.o main
