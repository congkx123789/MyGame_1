#pragma once
#include"Game.h"
using namespace std;
class MAP
{
public:
	MAP(const char* tittle, const char* file, SDL_Renderer* render, SDL_Rect screen, double* time);

	pair<pair<double, double>, pair<double, double>> giam_dan(pair<pair<double, double>, pair<double, double>> a, pair<pair<double, double>, pair<double, double>> b, double time);


	void Get_now_Screen(pair<pair<double, double>, pair<double, double>> a);

	void RenderCP();

	void GetScreen(SDL_Rect screen) { Screen = screen; }

	void updateVector(SDL_Rect gop);

	pair < SDL_Rect, double> VeX() { return make_pair(now, docheck); }

	SDL_Rect coll(SDL_Rect check, SDL_Rect old);

	void update();

	//void updateTIMEOLD() { TIMEold = *TIME; }

private:
	SDL_Rect Screen;
	SDL_Renderer* renderer;
	SDL_Texture** wall;
	double docheck;
	SDL_Texture* BackGround;
	SDL_Rect BackGR = { 0,0,0,0 };

	double* TIME;
	double TIMEold = 0;
	SDL_Rect now = { 0,0,0,0 };
	pair<pair<double, double>, pair<double, double>> now_double;

	double time_check;
};

