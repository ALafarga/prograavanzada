all:
	gcc main.c marriage.c -o marriage.exe
	./marriage.exe

main.o: main.c
	gcc -c main.c

marriage.o: marriage.c
	gcc -c marriage.c

test: main.o marriage.o
	gcc main.o marriage.o -o marriage.exe
	./maintest.tcl ./marriage.exe
