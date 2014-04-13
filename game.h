// game.h
// Wizard

#ifndef GAME_H
#define GAME_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#ifdef __APPLE__
#include <OpenGL/GL.h>
#else
#include <GL/gl.h>
#endif

class Game
{
public:
    Game();
    ~Game();

    void play();

private:
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;

    SDL_Window *window;
    SDL_GLContext glContext;

    bool run;

    bool setup();
    bool initSDL();
    bool initGL();

    void check_state();

};
#endif // GAME_H
