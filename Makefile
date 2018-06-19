CC=gcc

CFLAGS=-Wall
MAIN=engine
HEADERS=headers.h engine.h
FILES=engine.c board.c move.c

TEST=tests
TESTFILES=test_move.c move.c

all:main

main:engine.c
	$(CC) $(CFLAGS) $(FILES) -o $(MAIN)

clean:
	rm -rf *.o $(MAIN)

run:
	./$(MAIN)

test:
	$(CC) $(CFLAGS) -o $(TEST) $(TESTFILES) -lcriterion
	./$(TEST)
