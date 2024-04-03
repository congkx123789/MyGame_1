#pragma once
#include "Game.h"
#include "phantich.h"

class GameCharacter {
public:
    GameCharacter(const char* tittleofsheet, SDL_Renderer* renderer, int x, int y);

    void update(char key, bool check);
    void check();
    void resetSPE(SDL_Rect check);
    void SetADD(SDL_Rect ok) { Address = ok; }
    void GetTIME(double TIME) { TIMEnow = TIME; }
    void GetTIMEold() { TIMEold = TIMEnow; }
    SDL_Rect GetADD() { return Address; }
    SDL_Rect GetTA() { return testADD; }
    void render1(int x, int y);

private:
    double TIMEnow = 0;
    double TIMEold = 0;
    SDL_Rect testADD;
    SDL_Rect* sizePIC;
    SDL_Rect Address;
    SDL_Renderer* render;
    std::map<char, std::pair<int, SDL_Texture**>>* CharacterTex = nullptr;
};
