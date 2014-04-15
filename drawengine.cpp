// drawengine.cpp
// wizard

#include "drawengine.h"

DrawEngine::DrawEngine()
{

}

DrawEngine::~DrawEngine()
{

    std::cout << "~ Cleaning up drawengine \n";

    while( !loaded_textures.empty() )
    {
        delete loaded_textures.back();
        loaded_textures.pop_back();
    }

}

int DrawEngine::load_image( const char * filename )
{

    for ( int index = 0; index < loaded_textures.size(); index++ )
    {
        if ( strcmp( filename, loaded_textures[index]->file_name ) == 0 )
        {
            return index; // image already loaded in texture bucket
        }
    }
    
    SDL_Surface *surface;

    surface = IMG_Load( filename );
    if ( !surface )
    {
        std::cout << ">< Could not load " << filename << " \n";
        return -1;
    }

    GLint num_colors = surface->format->BytesPerPixel;
    GLenum color_mode;
    
    if ( num_colors == 3 ) // RGB 24bit
    {
        if (surface->format->Rmask == 0x000000ff)
        {
            std::cout << ">> 3 color RGB \n";
            color_mode = GL_RGB;
        }
        else
        {
            color_mode = GL_BGR;
        }
    }
    else if (num_colors == 4 ) // RGBA 32bit
    {
        if (surface->format->Rmask == 0x000000ff)
        {
            std::cout << ">> 4 color RGBA \n";
            color_mode = GL_RGBA;
        }
        else
        {
            color_mode = GL_BGRA;
        }
    }
    else
    {
        std::cout << ">< Unsure what format for glTexImage2D \n";
        SDL_FreeSurface( surface );
        return -2;
    }

    loaded_textures.push_back( new Texture );
    loaded_textures.back()->file_name = filename;
    loaded_textures.back()->gl_texture = 0;

    glGenTextures(1, &loaded_textures.back()->gl_texture);
    glBindTexture(GL_TEXTURE_2D, loaded_textures.back()->gl_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,0,num_colors,surface->w, surface->h, 0, color_mode, GL_UNSIGNED_BYTE, surface->pixels);

    // clean up
    if ( surface )
    {
        SDL_FreeSurface( surface );
    }

    return loaded_textures.size() - 1;

}
