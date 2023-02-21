CXX             = g++
OPT             = -O3
LDIR            = ../lib
IDIR        = ../include
LIBS            = -lraylib -lopengl32 -lgdi32 -lwinmm
CFLAGS          = $(OPT) -Wall -Wno-missing-braces -ffast-math -I $(IDIR) -L $(LDIR)

BINARY          = Game

OBJS            =  main.o Game.o Player.o Map.o
NOCONSOLE       = -mwindows

final : $(OBJS)
        $(CXX) $^ -o Renderer $(LIBS) $(CFLAGS) $(NOCONSOLE)
        rm *.o

all : $(BINARY)

$(BINARY) : $(OBJS)
        $(CXX) $^ -o $@ $(LIBS) $(CFLAGS)

main.o : ../src/main.cpp
        $(CXX) $(CFLAGS) -c ../src/main.cpp

Game.o : ../src/Game.cpp
        $(CXX) $(CFLAGS) -c ../src/Game.cpp

Map.o : ../src/Map.cpp
        $(CXX) $(CFLAGS) -c ../src/Map.cpp

Player.o : ../src/Player.cpp
        $(CXX) $(CFLAGS) -c ../src/Player.cpp


.PHONY :
        clean

run :
        ./Game.exe

clean:
        @echo "Cleaning Binary And Object Files"
        rm *.o Game.exe
