CC = gcc
CFLAGS = -Wall -g -Iinclude

all:
	$(CC)  $(CFLAGS) src/*.c  -o bin/a3 -lm
	make a3

a3:
	./bin/a3

clean:
	rm bin/a3
