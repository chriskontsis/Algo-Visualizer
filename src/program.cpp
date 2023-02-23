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

int main() 
{ 
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(1,99);
    vector<int> v;

    for(int i = 0; i < 100; i++) 
        v.push_back(dist(mt));
}

int bubbleSort(vector<int>& v) {

    
}

