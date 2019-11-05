all:	myTunes.o main.o
		gcc -o program myTunes.o main.o

myTunes.o:	myTunes.c myTunes.h
		gcc -c myTunes.c
		
main.o: main.c myTunes.h
		gcc -c main.c
		
run:
		./program
		
clean:
		rm *.o
		rm *~