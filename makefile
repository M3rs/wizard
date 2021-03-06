#Detect OS
UNAME = $(shell uname)

#Build
build:
	make $(UNAME)

Linux:
	g++ -c main.cpp
	g++ -std=c++11 -c game.cpp
	g++ -c menustate.cpp
	g++ -std=c++11 -c drawengine.cpp
	g++ -Wall main.o game.o menustate.o drawengine.o -o wizard -lSDL2 -lSDL2_image -lGL

Darwin:
	g++ -c main.cpp
	g++ -std=c++11 -c game.cpp
	g++ -c menustate.cpp
	g++ -std=c++11 -c drawengine.cpp
	g++ -Wall main.o game.o menustate.o drawengine.o -o wizard -lSDL2 -lSDL2_image -lSDL2_ttf -framework OpenGL

run:
	./wizard

clean:
	rm *.o
	rm wizard
