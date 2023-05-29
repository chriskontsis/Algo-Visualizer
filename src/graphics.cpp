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
                    is_running = false;
                    cout << "Exiting Visualuzer" << '\n';
                    break;
                }
                case (SDLK_0):
                {
                    cout << "Starting Bubble Sort" << '\n';
                    sort->bubbleSort(v, renderer);
                    cout << "Bubble Sort Finished" << '\n';
                    sort->generateVector(v);
                    break;
                }
                case(SDLK_1): 
                {
                    cout << "Starting Quicksort" << '\n';
                    sort->quickSort(v, renderer, 0, v.size()-1);
                    cout << "Quicksort finished" << '\n';
                    sort->generateVector(v);
                    break;
                }
                case(SDLK_2):
                {
                    cout << "Starting Insertion Sort" << '\n';
                    sort->quickSort(v, renderer, 0, v.size()-1);
                    cout << "Insertion Sort Finished" << '\n';
                    sort->generateVector(v);
                    break;
                }
                }
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::draw(vector<int> &vec, SDL_Renderer *renderer, unsigned int left, unsigned int right)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vec.size(); i++)
    {
        SDL_Rect rect = {i, 99 - vec[i], 1, vec[i]};
        if (i == left)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (i == right)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderPresent(renderer);
}
