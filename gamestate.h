// gamestate.h
// Wizard
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

#include <SDL2/SDL.h>

enum GS_MESSAGE {GS_NONE, GS_QUIT};

class GameState
{
public:
    virtual ~GameState() {};

    virtual void init()=0;
    virtual void cleanup()=0;

    virtual void handle_events( SDL_Event * ev )=0;
    virtual void update()=0; // TODO: pass in time some how
    virtual void render()=0; // pass draw engine pointer ???

    int message;
};
#endif // gamestate.h
