#include "menustate.h"

MenuState::~MenuState()
{
    // destructor
    std::cout << "MenuState Destroyed??? \n";
}

void MenuState::init()
{
   std::cout << "MenuState init \n";

}

void MenuState::cleanup()
{
    std::cout << "~Cleaning up MenuState \n";

}

void MenuState::handle_events( SDL_Event * ev )
{

    while ( SDL_PollEvent( ev ) )
    {
        switch ( ev->type )
        {
        case SDL_QUIT:
           message = GS_QUIT;
           break;
        }
    }
}

void MenuState::update()
{

}

void MenuState::render()
{

}
