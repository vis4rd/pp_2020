lab14_1.exe: lab14_1.o cycle.o
	gcc -o lab14_1.exe cycle.o lab14_1.o -Wall
cycle.o: cycle.c cycle.h
	gcc -c cycle.c -Wall
lab14_1.o: lab14_1.c cycle.h
	gcc -c lab14_1.c -Wall