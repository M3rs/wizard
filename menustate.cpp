#include "menustate.h"

MenuState::~MenuState()
{
    // destructor
    std::cout << "MenuState Destroyed??? \n";

    glDeleteTextures(1, &menutext);
}

void MenuState::init()
{
   std::cout << "MenuState init \n";

   TTF_Font *gFont = TTF_OpenFont("spellstone4.ttf",48);
   if ( !gFont )
   {
       std::cout << "-Failed to load font \n";
   }

   SDL_Color textColor = {0,0,0};
   SDL_Surface *text = TTF_RenderText_Blended(gFont,"Test",textColor);
   if ( !text )
   {
       std::cout << "-Failed tor ender text \n";
   }
    
   menutext = 0;

   glGenTextures(1, &menutext);
   glBindTexture(GL_TEXTURE_2D, menutext);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, text->w, text->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, text->pixels);


   TTF_CloseFont(gFont);
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
        case SDL_KEYDOWN:
            switch ( ev->key.keysym.sym )
            {
            case SDLK_ESCAPE:
                message = GS_QUIT;
                break;
            }
        }
    }
}

void MenuState::update()
{

}

void MenuState::render()
{


    // draw background
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glBegin( GL_QUADS );
    glColor3f(0,1,0);
    glVertex2f(0,0);
    glColor3f(0,1,0);
    glVertex2f(640, 0);
    glColor3f(0,1,0);
    glVertex2f(640, 480);
    glColor3f(0,1,0);
    glVertex2f(0,480);
    glEnd();



}
