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
            graphic->draw(v, renderer, i, j);
            SDL_Delay(10);
        }
    }
}

void SortingAlgos::quickSort(std::vector<int> &v, SDL_Renderer *renderer, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = quickSortPartition(v, lo, hi);
        quickSort(v, renderer, lo, pi - 1);
        quickSort(v, renderer, pi + 1, hi);
    }
}

int SortingAlgos::quickSortPartition(std::vector<int> &v, int lo, int hi)
{
    int pivot = v[hi];
    int i = (lo - 1);

    for (int j = lo; j < hi; j++)
    {
        if (v[j] < pivot)
        {
            ++i;
            swap(&v[i], &v[j]);
        }
    }

    swap(&v[i + 1], &v[hi]);
    return (i + 1);
}

void SortingAlgos::swap(int *a, int *b)
{
    int t = *a;
    *a - *b;
    *b = t;
}
void SortingAlgos::generateVector(std::vector<int> &v)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(1, 99);

    for (int i = 0; i < 100; i++)
        v[i] = dist(mt);
}