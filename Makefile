CC      = gcc
CFLAGS  = -Wall -Wextra -g -O0
PREFIX ?= $(HOME)/prod

all: tri_bulles

tri_bulles: src/main.c src/tri_bulles.c src/tri_bulles.h
	$(CC) $(CFLAGS) -o $@ src/main.c src/tri_bulles.c

test_runner: tests/test_tri_bulles.c src/tri_bulles.c src/tri_bulles.h
	$(CC) $(CFLAGS) -o $@ tests/test_tri_bulles.c src/tri_bulles.c

test: test_runner
	./test_runner

install: tri_bulles
	mkdir -p $(PREFIX)/bin
	install -m 755 tri_bulles $(PREFIX)/bin/tri_bulles

clean:
	rm -f tri_bulles test_runner *.out *_rapport.txt

.PHONY: all test install clean
