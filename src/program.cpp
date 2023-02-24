#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
void draw(vector<int>& vec, SDL_Renderer* renderer, unsigned int i, unsigned int j) 
{
    for(int i = 0; i < vec.size(); i++) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, i, 99, i, vec[i]);
    }
}


void bubble(vector<int>& v, SDL_Renderer* renderer) {
    int n = v.size();
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
            // Clear the screen
            SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
            SDL_RenderClear(renderer);

            // Draw the state
            draw(v, renderer, i,j);

            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
}


int main() 
{ 
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(1,99);
    vector<int> v;

    for(int i = 0; i < 100; i++) 
        v.push_back(dist(mt));

    SDL_Init(SDL_INIT_VIDEO); 
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10,10);


    
    // bubble(v, renderer);



    //SDL_Window *window;                    // Declare a pointer

             // Initialize SDL2

// Create an application window with the following settings:
// window = SDL_CreateWindow(
//     "An SDL2 window",                  // window title
//     SDL_WINDOWPOS_UNDEFINED,           // initial x position
//     SDL_WINDOWPOS_UNDEFINED,           // initial y position
//     640,                               // width, in pixels
//     480,                               // height, in pixels
//     SDL_WINDOW_OPENGL                  // flags - see below
// );

// // Check that the window was successfully created
// if (window == NULL) {
//     // In the case that the window could not be made...
//     printf("Could not create window: %s\n", SDL_GetError());
//     return 1;
// }

// // A basic main loop to prevent blocking
bool is_running = true;
SDL_Event event;
while (is_running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running = false;
        }
        else {
            bubble(v, renderer);
        }
    }
    SDL_Delay(16);
}

// // Close and destroy the window
// SDL_DestroyWindow(window);

// // Clean up
// SDL_Quit();
// return 0;

}


