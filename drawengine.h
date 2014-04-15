// drawengine.h
// wizard

#ifndef DRAWENGINE_H
#define DRAWENGINE_H

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>

struct Texture
{
    const char * file_name;
    GLuint gl_texture;
};

class DrawEngine
{
public:
    DrawEngine();
    ~DrawEngine();

    std::vector<Texture*> loaded_textures;

    int load_bmp( const char * filename );

};

#endif // drawengine.h
