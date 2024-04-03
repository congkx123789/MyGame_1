#pragma once
#include"Game.h"
class MAP
{
public:

	MAP(const char* tittle, SDL_Renderer* render, SDL_Rect screen);

	void RenderCP();

	void GetScreen(SDL_Rect screen) { Screen = screen; }

	void updateVector(SDL_Rect old);

	int VeX() { return x; }

	int veY() { return y; }

	SDL_Rect coll(SDL_Rect check, SDL_Rect old);

	void update();

private:
	SDL_Rect Screen;
	SDL_Renderer* renderer;
	SDL_Texture** wall;

	int x, y;

};

