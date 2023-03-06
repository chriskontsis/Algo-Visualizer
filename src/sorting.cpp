#include "graphics.h"
#include <algorithm>
#include <random>
#include <utility>



void SortingAlgos::bubbleSort(std::vector<int>& v, SDL_Renderer* renderer) {
    int n = v.size();
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j+1]) {
                std::swap(v[j], v[j+1]);
            }
            // Draw the state
            graphic->draw(v, renderer, i,j);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
}



