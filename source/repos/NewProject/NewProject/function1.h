#pragma once
#include"Game.h"

class function1
{
public:

	SDL_Texture* Manager_Texture(const char* tittle, SDL_Renderer* renderer) {
		SDL_Surface* surface1 = IMG_Load(tittle);
		SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
		SDL_FreeSurface(surface1);
		return texture1;
	}

	void answer1(SDL_Rect add, double w, double h);

	bool checkSDL1(SDL_Rect check, SDL_Rect add)
	{
		if (check.y + check.h <= add.y || check.x >= add.x + add.w || check.x + check.w <= add.x || check.y >= add.y + add.h)
			return true;
		return false;
	}

	bool checkDouble(double w, double h, SDL_Rect add);

	void setDouble_AndOld(double a, double b, SDL_Rect Old) {
		first1 = a;
		second1 = b;
		old = Old;
	}

	int reDoubleF() { return int(first1); }

	int reDoubleS() { return int(second1); }

	void lamtron()
	{
		bool check1;
		if (first1 < 0)check1 = 1;
		else check1 = 0;
		if (check1) first1 = abs(first1);
		if (first1 - int(first1) > 0.5)
			first1 = int(first1) + 1;
		else
			first1 = int(first1);
		if (check1) first1 = first1 * (-1.0);

		if (second1 < 0)check1 = 1;
		else check1 = 0;
		if (check1) second1 = abs(second1);
		if (second1 - int(second1) > 0.5)
			second1 = int(second1) + 1;
		else
			second1 = int(second1);
		if (check1) second1 = second1 * (-1.0);
	}

private:

	double first1;
	double second1;
	SDL_Rect old;

};

