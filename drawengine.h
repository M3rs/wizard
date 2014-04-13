// drawengine.h
// wizard

#ifndef DRAWENGINE_H
#define DRAWENGINE_H

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class DrawEngine
{
public:
    DrawEngine();
    ~DrawEngine();

    std::vector<GLuint*> textures;

    int load_bmp();

};

#endif // drawengine.h
