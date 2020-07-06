CC=gcc
SRC:=$(wildcard src/*.c)
SIM_SRC:=$(wildcard src/include/simulation/*.c)
WCE_SRC:=$(wildcard src/include/wce/*.c)
CFLAGS= -Isrc/include/ -lSDL2 -lGL -o main

main: src/*

	$(CC) $(SRC) $(SIM_SRC) $(WCE_SRC) $(CFLAGS)