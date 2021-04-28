all:main.c sort.o randdata.o
	gcc randdata.o -o rand
	./rand
	gcc main.c sort.o -o main
	./main qk n
	./main mg n
	./main rd n
	./main qk w
	./main mg w
	./main rd w
	cat result.txt

sort.o: sort.h sort.c
	gcc -c sort.c -o sort.o

randdata.o: sort.h randgener.c
	gcc -c randgener.c -o randdata.o

clean:
	rm -f sort.o randdata.o dataset1.txt dataset2.txt result.txt rand main
