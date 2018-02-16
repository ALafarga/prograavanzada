LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c proyecto1.c
	 gcc -c main.c
	 gcc -o proyecto1.exe proyecto1.o main.o $(LIB)

proyecto1test: clean
	 gcc -c proyecto1.c
	 gcc -c proyecto1test.c
	 gcc -o proyecto1test.exe proyecto1.o proyecto1test.o
	 ./proyecto1test.exe

test:	 proyecto1test

clean:
	 rm *.out *.o *.exe || exit 0

proyecto1: clean
	 gcc -c proyecto1.c
	 gcc -c main.c
	 gcc -o proyecto1.exe proyecto1.o main.o $(LIB)

run: proyecto1
	 ./proyecto1.exe

runtest: proyecto1
	 ./maintest.tcl ./proyecto1.exe

