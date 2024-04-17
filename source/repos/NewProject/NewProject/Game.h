#pragma once
#include <map>
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "fstream"
#include <math.h>
#include "function1.h"
#include"animation.h"
#include "phantich.h"
#include"man_hinh_cho.h"
#include "speed.h"
#include "GameCharacter.h" 
#include "MAP.h"

using namespace std;

class My_Game {
public:
    void init(const char* tittle, int xrow, int ycolum, bool Full_Screen);
    bool man_hinh();
    void SetTime(Uint32 time) { *TIMENOW = time / 1000.0; }
    void return_All_time();
    bool running1();
    void change();

    void analy();
    void analy1();
    void render1();

    void ALLold();
    void Systems_Clear();
private:
    double *TIMENOW = new double;
    SDL_Window* window;
    SDL_Event event;
    bool ren=1;
    SDL_Rect Screen;
    SDL_Renderer* renderer;
};
