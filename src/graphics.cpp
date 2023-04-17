#include "graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

const int WIDNOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void Graphics::draw(std::vector<int> &vec, SDL_Renderer *renderer, unsigned int left, unsigned int right)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vec.size(); i++)
    {
        SDL_Rect rect = {i, 99 - vec[i], 1, vec[i]};
        if (i == left)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (i == right)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // SDL_RenderDrawLine(renderer, i, 99, i, vec[i]);
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderPresent(renderer);
}

SDL_Window *Graphics::createWindow()
{
    SDL_Window *window = nullptr;
    window = SDL_CreateWindow(
        "An SDL2 window",        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        WIDNOW_WIDTH,            // width, in pixels
        WINDOW_HEIGHT,           // height, in pixels
        SDL_WINDOW_OPENGL        // flags - see below
    );
    return window;
}