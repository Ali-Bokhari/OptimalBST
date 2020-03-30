CC = gcc
CFLAGS = -Wall -g -Iinclude

all:
	$(CC)  $(CFLAGS) src/*.c  -o bin/a4
	make a4

a4:
	./bin/a4

clean:
	rm bin/a4
