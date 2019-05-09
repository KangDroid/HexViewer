CC=gcc-8
CFLAGS=-Wall -O3

all: code.o dumpHex.o showHex.o
	gcc-8 $(CFLAGS) -o app.out code.o dumpHex.o showHex.o

code.o:
	gcc-8 $(CFLAGS) -c -o code.o code.c

dumpHex.o:
	gcc-8 $(CFLAGS) -c -o dumpHex.o dumpHex.c

showHex.o:
	gcc-8 $(CFLAGS) -c -o showHex.o showHex.c

clean:
	rm -rf ./*.out ./*.o