#Makefile

main: main.o hangman.o
	g++ main.o hangman.o -o main

main.o: main.cpp hangman.h
	g++ -c main.cpp

hangman.o: hangman.cpp hangman.h
	g++ -c hangman.cpp

test: test.o hangman.o
	g++ test.o hangman.o -o test

test.o: test.cpp hangman.h
	g++ -c test.cpp

clean:
	/bin/rm -f *.o main