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
using namespace std;

int main()
{
    SortingAlgos *sort = new SortingAlgos;
    vector<int> v(100);
    sort->generateVector(v);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    // SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
    // SDL_RenderSetScale(renderer,10,10);
    window = SDL_CreateWindow(
        "An SDL2 window",        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        WIDNOW_WIDTH,            // width, in pixels
        WINDOW_HEIGHT,           // height, in pixels
        SDL_WINDOW_OPENGL        // flags - see below
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(renderer, 6, 4);

    // // A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;
    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case (SDLK_q):
                {
                    is_running = true;
                    cout << "Exiting Visualuzer" << '\n';
                    break;
                }
                case (SDLK_0):
                {
                    cout << "Starting Bubble Sort" << '\n';
                    sort->bubbleSort(v, renderer);
                    cout << "Bubble Sort Finished" << '\n';
                    break;
                }
                }
            }
        }
        SDL_Delay(16);
    }

    // // Close and destroy the window
    SDL_DestroyWindow(window);

    // // Clean up
    SDL_Quit();
    // return 0;
}

void Graphics::draw(vector<int> &vec, SDL_Renderer *renderer, unsigned int left, unsigned int right)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vec.size(); i++)
    {
        if (i == left)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (i == right)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, i, 99, i, vec[i]);
    }
    SDL_RenderPresent(renderer);
}