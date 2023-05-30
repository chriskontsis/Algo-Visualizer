#ifndef _SORTING_H_
#define _SORTING_H_
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 
#include <vector>

class Graphics;

class SortingAlgos {
public:
    Graphics* graphic;
    void generateVector(std::vector<int> &vec);
    void bubbleSort(std::vector<int>& v, SDL_Renderer* renderer);
    void mergeSort(std::vector<int>& v, SDL_Renderer* renderer);
    int partition(std::vector<int>& v, SDL_Renderer* renderer, int lo, int hi);
    void heapSort(std::vector<int>& v, SDL_Renderer* renderer);
    void heapify(std::vector<int>& v, SDL_Renderer* renderer, int n, int i);
    void insertionSort(std::vector<int>& v, SDL_Renderer* renderer);
    void quickSort(std::vector<int>& v, SDL_Renderer* renderer, int lo, int hi);
};

#endif