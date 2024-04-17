#pragma once
#include"Game.h"
using namespace std;
class MAP
{
public:

	MAP(const char* tittle, const char* file, SDL_Renderer* render, SDL_Rect screen);

	void RenderCP();

	void GetScreen(SDL_Rect screen) {Screen = screen;}

	void updateVector(SDL_Rect gop);

	pair < SDL_Rect, double> VeX() { return make_pair(now, docheck); }

	SDL_Rect coll(SDL_Rect check, SDL_Rect old);

	void update();

private:
	SDL_Rect Screen;
	SDL_Renderer* renderer;
	SDL_Texture** wall;
	double docheck;
	SDL_Texture* BackGround;
	SDL_Rect BackGR = {0,0,0,0};
	SDL_Rect now;
};

