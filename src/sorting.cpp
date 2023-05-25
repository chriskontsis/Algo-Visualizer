#include "graphics.h"
#include <algorithm>
#include <random>
#include <utility>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


void SortingAlgos::bubbleSort(std::vector<int> &v, SDL_Renderer *renderer)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
            graphic->draw(v, renderer, i, j);
            SDL_Delay(10);
        }
    }
}

void SortingAlgos::quickSort(std::vector<int>& v, SDL_Renderer *renderer, int lo, int hi) {

    if(lo < hi) {
        int pivot = partition(v, renderer, lo, hi);
        quickSort(v, renderer, lo, pivot-1);
        quickSort(v, renderer, pivot+1, hi);
    }
}

int SortingAlgos::partition(std::vector<int>& v, SDL_Renderer *renderer, int lo, int hi) {
    int pivot = v[hi];
    int i = (lo-1);

    for(int j = lo; j < hi; j++) {
        if(v[j] < pivot) {
            ++i;
            std::swap(v[i], v[j]);
            graphic->draw(v, renderer, i,j);
            SDL_Delay(20);
        }
        if(i > -1)
             graphic->draw(v, renderer, i,j);
        SDL_Delay(20);
    }

    std::swap(v[i+1], v[hi]);
    graphic->draw(v, renderer, i+1, hi);
    SDL_Delay(20);
    return i+1;
}

void SortingAlgos::insertionSort(std::vector<int>& v, SDL_Renderer* renderer) {
    
}
void SortingAlgos::generateVector(std::vector<int> &v)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, 99);

    for (int i = 0; i < 100; i++)
        v[i] = dist(mt);
}