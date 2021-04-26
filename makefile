all:main.c sort.o randdata.o
	gcc randdata.o -o rand
	./rand
	gcc main.c sort.o -o main

sort.o: sort.h sort.c
	gcc -c sort.c -o sort.o

randdata.o: sort.h randgener.c
	gcc -c randgener.c -o randdata.o

clean:
	rm -f sort.o randdata.o dataset1.txt dataset2.txt main
