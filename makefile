wizard:
	g++ -c main.cpp
	g++ -c game.cpp
	g++ -Wall main.o game.o -o wizard -lSDL2 -framework OpenGL

run:
	./wizard

clean:
	rm *.o
	rm wizard
