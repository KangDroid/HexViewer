CC=gcc-8
CFLAGS=-g -Wall -O3
TARGET=app.out
OBJS=code.o \
	dumpHex.o \
	showHex.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf ./*.out ./*.o ./*.dSYM