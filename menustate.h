// menustate.h
// wizard

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <iostream>

#include <SDL2/SDL.h>

#include "gamestate.h"

class MenuState : public GameState
{
public:
    ~MenuState();

    void init();
    void cleanup();

    void handle_events( SDL_Event * ev );
    void update(); // TODO: pass in time
    void render(); // pointer for renderer??
};
#endif // menustate.h
