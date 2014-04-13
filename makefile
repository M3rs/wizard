#Detect OS
UNAME = $(shell uname)

#Build
build:
	make $(UNAME)

Linux:
	g++ -c main.cpp
	g++ -std=c++11 -c game.cpp
	g++ -c menustate.cpp
	g++ -Wall main.o game.o menustate.o -o wizard -lSDL2 -lGL

Darwin:
	g++ -c main.cpp
	g++ -c game.cpp
	g++ -c menustate.cpp
	g++ -Wall main.o game.o menustate.o -o wizard -lSDL2 -framework OpenGL

run:
	./wizard

clean:
	rm *.o
	rm wizard
