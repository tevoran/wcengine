CC=gcc
SRC:=$(wildcard src/*.c)
SIM_SRC:=$(wildcard src/include/simulation/*.c wildcard src/include/simulation/shaders/*.c )
WCE_SRC:=$(wildcard src/include/wce/*.c)
CFLAGS= -Isrc/include/ -lSDL2 -lGL -lGLEW -lm -o main

main: $(SRC) $(SIM_SRC) $(WCE_SRC)

	$(CC) $(SRC) $(SIM_SRC) $(WCE_SRC) $(CFLAGS)