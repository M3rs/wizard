// drawengine.cpp
// wizard

#include "drawengine.h"

DrawEngine::DrawEngine()
{

}

DrawEngine::~DrawEngine()
{

}

int DrawEngine::load_bmp( const char * filename )
{
    
    SDL_Surface *surface;
    GLuint texture;

    surface = IMG_Load( filename );
    if ( !surface )
    {
        std::cout << ">< Could not load " << filename << " \n";
        return -1;
    }

    int color_mode;
    if ( surface->format->BytesPerPixel == 3 ) // RGB 24bit
    {
        color_mode = GL_RGB;
    }
    else if (surface->format->BytesPerPixel == 4 ) // RGBA 32bit
    {
        color_mode = GL_RGBA;
    }
    else
    {
        std::cout << ">< Unsure what format for glTexImage2D \n";
        SDL_FreeSurface( surface );
        return -2;
    }

    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, color_mode, surface->w, surface->h, 0, color_mode, GL_UNSIGNED_BYTE, surface->pixels);

    // for how texture is drawn later
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // clean up
    SDL_FreeSurface( surface );

    textures.push_back( texture );

    return textures.size() - 1;

}
