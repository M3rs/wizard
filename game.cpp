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

    return true;

}

bool Game::initSDL()
{
    if ( SDL_Init( SDL_INIT_EVERYTHING) == -1 )
    {
        std::cout << "- SDL_Init() failed \n";
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

    glViewport( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );

    // Init projection matrix
    glMatrixMode( GL_PROJECTION );
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

    SDL_Event ev;

    while ( run )
    {
        while ( SDL_PollEvent( &ev ) )
        {
            if ( ev.type == SDL_QUIT )
            {
                run = false;
            }
        }

        // state->handle_events(ev);
        // state->update(time);
        // check_state();
        // state->render();

    }


}

void Game::check_state()
{
    // switch( state->message ) ??
    // case GS_QUIT:
    //  run = false;
    //  break;


}
