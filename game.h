// game.h
// Wizard

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>

#ifdef __APPLE__
#include <OpenGL/GL.h>
#else
#include <GL/gl.h>
#endif

#include "drawengine.h"

#include "gamestate.h"
#include "menustate.h"

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

    DrawEngine renderer;
    std::vector<GameState*> states;

    bool run;

    bool setup();
    bool initSDL();
    bool initGL();

    void check_state();

};
#endif // GAME_H
