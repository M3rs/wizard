#Detect OS
UNAME = $(shell uname)

#Build
build:
	make $(UNAME)

Linux:
	g++ -c main.cpp
	g++ -std=c++11 -c game.cpp
	g++ -c menustate.cpp
	g++ -c drawengine.cpp
	g++ -Wall main.o game.o menustate.o drawengine.o -o wizard -lSDL2 -lGL

Darwin:
	g++ -c main.cpp
	g++ -std=c++11 -c game.cpp
	g++ -c menustate.cpp
	g++ -c drawengine.cpp
	g++ -Wall main.o game.o menustate.o drawengine.o -o wizard -lSDL2 -framework OpenGL

run:
	./wizard

clean:
	rm *.o
	rm wizard
