#include "graphics.h"
#include <algorithm>
#include <random>
#include <utility>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

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
            // Draw the state
            graphic->draw(v, renderer, i, j);
            SDL_Delay(10);
        }
    }
}

void SortingAlgos::generateVector(std::vector<int> &v)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(1, 99);

    for (int i = 0; i < 100; i++)
        v[i] = dist(mt);
}