CC=g++
CFLAGS=-c -g -Wall -pedantic
LDFLAGS=-g -O3
SRC_DIR=src/
BIN_DIR=bin/
BIN_FILES=$(BIN_DIR)main.o $(BIN_DIR)addition.o

.PHONY: clean prebuild all

all: prebuild $(BIN_FILES)
	$(CC) $(LDFLAGS) $(BIN_FILES)

prebuild:
	mkdir -p $(BIN_DIR)

$(BIN_DIR)main.o: $(SRC_DIR)main.cpp
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIR)addition.o: $(SRC_DIR)addition.cpp $(SRC_DIR)addition.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	cd $(BIN_DIR) && rm -f *.o *.out
