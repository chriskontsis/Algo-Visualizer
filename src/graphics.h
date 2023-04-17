#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "sorting.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <algorithm>

class Graphics
{
public:
    // Graphics();
    void draw(std::vector<int> &vec, SDL_Renderer *renderer, unsigned int i, unsigned int j);
    SDL_Window *createWindow();
};

#endif