#pragma once
#include"Game.h"
using namespace std;
class man_hinh_cho
{
public:
	man_hinh_cho(const char* file, SDL_Renderer* render, SDL_Rect screen);
	void render_tuto();
	void render1();
	void render2(bool a);
	bool man_hinh_tuto();
	bool man_hinh_cho_1();
	int man_hinh_cho_2(bool a);
private:
	SDL_Renderer* renderer;
	pair<SDL_Rect, SDL_Texture*> start;
	pair<SDL_Rect, SDL_Texture*> restart;
	pair<SDL_Rect, SDL_Texture*> exit;
	pair<SDL_Rect, SDL_Texture*> resume;
	pair<SDL_Rect, SDL_Texture*> Exit_2;
	pair<SDL_Rect, SDL_Texture*> menu;
	pair<SDL_Rect, SDL_Texture*> tutorial;
	SDL_Texture*tutorial_image;
	SDL_Texture* background;
	SDL_Rect Screen;
};

