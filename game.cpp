// game.cpp
// Wizard

#include "game.h"

Game::Game() : SCREEN_WIDTH(640), SCREEN_HEIGHT(480)
{
    std::cout << "Game Created! \n";

    window = NULL;

    run = true;
}

Game::~Game()
{
    std::cout << ">> Cleaning up game: \n";
    
    for ( auto& state : states )
    {
        state->cleanup();
        delete state;
    }

    if ( glContext )
    {
        SDL_GL_DeleteContext( glContext );
        std::cout << "~ Destroyed Open GL Context \n";
    }

    if ( window )
    {
        SDL_DestroyWindow( window );
        std::cout << "~ Destroyed Window \n";
    }
    
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

}

bool Game::setup()
{
    if ( !initSDL() )
    {
        std::cout << "- Failed to init SDL \n";
        return false;
    }

    if ( !initGL() )
    {
        std::cout << "- Failed to init Open GL \n";
        return false;
    }

    std::cout << "Game setup was successful! \n";
    
    states.push_back( new MenuState );
    states.back()->message = GS_NONE;

    return true;

}

bool Game::initSDL()
{
    if ( SDL_Init( SDL_INIT_EVERYTHING) == -1 )
    {
        std::cout << "- SDL_Init() failed \n";
        return false;
    }

    if ( !IMG_Init (IMG_INIT_PNG) )
    {
        std::cout << "- IMG_Init() failed \n";
        return false;
    }

    if ( TTF_Init() == -1 )
    {
        std::cout << "- TTF_Init() failed \n";
        return false;
    }

    // Set Open GL Version to 2.1
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Create SDL_Window for Open GL
    window = SDL_CreateWindow("Wizard",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    if ( !window )
    {
        std::cout << "- Failed to created window \n";
        return false;
    }

    // Create Open GL Context
    glContext = SDL_GL_CreateContext( window );
    if ( !glContext )
    {
        std::cout << "- Failed to created open GL context \n";
        return false;
    }

    if ( SDL_GL_SetSwapInterval( 1 ) < 0 )
    {
        std::cout << " -- Warning: undable to set VSync \n";
    }

    return true;

}

bool Game::initGL()
{

    GLenum error = GL_NO_ERROR;

    glEnable( GL_TEXTURE_2D );

    glEnable( GL_ALPHA_TEST );
    glAlphaFunc( GL_GREATER, 0.5 );

    glEnable( GL_BLEND ); // used with TTF
    //glAlphaFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);

    glViewport( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );

    // Init projection matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // VERY IMPORTANT TO SET THIS !!!!!!!!!!!!!!!!!!!!!!!!
    glOrtho(0.f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.f, -1.f, 1.f);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    error = glGetError();
    if ( error != GL_NO_ERROR )
    {
        std::cout << "- Error initializing open GL: " << error << "\n";
        return false;
    }

    // Initialize clear color (white)
    glClearColor( 1.f, 1.f, 1.f, 1.f );

    error = glGetError();
    if ( error != GL_NO_ERROR )
    {
        std::cout << "=Error initializing open GL: " << error << "\n";
        return false;
    }

    return true;
}

void Game::play()
{

    if ( !setup() )
    {
        std::cout << "-Failed to setup game";
        return;
    }

    DrawEngine renderer;
    int i;
    i = renderer.load_image( "background.png" );
    if ( i < 0 )
    {
        std::cout << "error loading image \n";
    }

    int j = renderer.load_image( "test1.png" );


    SDL_Event ev;

    while ( run )
    {

        states.back()->handle_events( &ev );
        states.back()->update();
        check_state();
        glClear( GL_COLOR_BUFFER_BIT);
        states.back()->render();

        /*
        // testing code:
        //glClear( GL_COLOR_BUFFER_BIT );
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslated(100,100,0);
        glBindTexture(GL_TEXTURE_2D, renderer.loaded_textures[j]->gl_texture );
        //glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex2f(0,0);
        glTexCoord2i(1,0);
        glVertex2f(100,0);
        glTexCoord2i(1,1);
        glVertex2f(100,100);
        glTexCoord2i(0,1);
        glVertex2f(0,100);
        glEnd();
        
        // testing code:
        //glClear( GL_COLOR_BUFFER_BIT );
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslated(50,100,0);
        glBindTexture(GL_TEXTURE_2D, renderer.loaded_textures[i]->gl_texture );
        //glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glTexCoord2i(0,0);
        glVertex2f(0,0);
        glTexCoord2i(1,0);
        glVertex2f(100,0);
        glTexCoord2i(1,1);
        glVertex2f(100,100);
        glTexCoord2i(0,1);
        glVertex2f(0,100);
        glEnd();

        */

        SDL_GL_SwapWindow( window );

    }


}

void Game::check_state()
{
    switch( states.back()->message )
    {
    case GS_QUIT:
        run = false;
        break;
    }
    // case GS_QUIT:
    //  run = false;
    //  break;


}
