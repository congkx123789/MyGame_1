#pragma once
#include "Game.h"
using namespace std;

class GameCharacter {
public:
    GameCharacter(const char* tittleofsheet, SDL_Renderer* renderer,double *time, int x, int y);
    bool ch(char check1);
    void update(char key, bool check);
    void check();
    void resetSPE(SDL_Rect check);
    void SetADD(SDL_Rect ok) { Address = ok; }
    pair<SDL_Rect, pair<int, SDL_Rect>> Set_Imae();
    
    SDL_Rect GetADD() { return Address; }

    SDL_Rect GetTA() { return testADD; }
    void render1(pair<SDL_Rect, double>Screen1);
    void GetTIMEold() { TIMEold = *TIMEnow; }
    double getTIMEOLD() { return TIMEold; }
    void effect(int a);
    bool runni() { return HP > 0; }
    void return_ALL();


private:
    SDL_Renderer* render;
    //time
    double *TIMEnow;
    double TIMEold = 0;

    //mainTex
    map<char, pair<int, SDL_Texture**>>* CharacterTex = nullptr;
    SDL_Rect testADD;
    SDL_Rect *sizePIC;
    SDL_Rect Address;

    map<char, map<int, pair<int, SDL_Rect>>> Sat_Thuong;

    //health
    double HP = 20.0;
    SDL_Rect health;
    SDL_Rect addhealth;
    SDL_Texture* health_bar;

    // initial
    double HPold = HP;
    SDL_Rect Address_old;
};
