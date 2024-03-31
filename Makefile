CC=clang
CFLAGS=-Wall -g


all: test

pixpen.o: pixpen.c pixpen.h
	$(CC) $(CFLAGS) -c pixpen.c

test: test.c pixpen.o
	$(CC) $(CFLAGS) -o $@ $^ -g -lm


clean:
	rm *.o  test
