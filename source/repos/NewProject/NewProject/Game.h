#pragma once
#include <map>
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "fstream"
#include <math.h>
#include "phantich.h" // Bao g?m ??nh ngh?a c?a l?p phantich
#include "function1.h"
#include "speed.h"
#include "GameCharacter.h" // Bao g?m ??nh ngh?a c?a l?p GameCharacter
#include "MAP.h"

using namespace std;

class My_Game {
public:
    void init(const char* tittle, int xrow, int ycolum, bool Full_Screen);
    void render1();
    bool running1();
    void SetTime(Uint32 time) {
        double a = time;
        TIMENOW = a / 1000;
    }
    void Systems_Clear();
    void analy();
    void change();
    void ALLold();
    void return_All_time();

private:
    double TIMENOW;
    SDL_Window* window;
    SDL_Event event;
    SDL_Rect Screen;
    SDL_Renderer* renderer;
};
