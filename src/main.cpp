#include "graphics.h"
#include "sorting.h"
#include <iostream>

using namespace std;

int main()
{
    unique_ptr<SortingAlgos> sort;
    unique_ptr<Graphics> graphic;
    vector<int> v(100);
    sort->generateVector(v);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = graphic->createWindow();

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(renderer, 6, 4);

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
                    std::cout << "Exiting Visualuzer" << '\n';
                    break;
                }
                case (SDLK_0):
                {
                    std::cout << "Starting Bubble Sort" << '\n';
                    sort->bubbleSort(v, renderer);
                    cout << "Bubble Sort Finished" << '\n';
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