#pragma once
#include"Game.h"
using namespace std;
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

	SDL_Rect gop(SDL_Rect old, SDL_Rect check) { return { min(check.x,old.x),min(check.y,old.y),check.w + abs(check.x - old.x),check.h + abs(check.y - old.y) }; }

	pair<pair<double, double>, pair<double, double>> center(pair<pair<double, double>, pair<double, double>> check, double w1, double h1, SDL_Rect BackGR);

	SDL_Rect nhan(SDL_Rect hazz, double ab);

	double chia(int a, int b);

	SDL_Rect congSDL(SDL_Rect basis, SDL_Rect cong_SDL);

	SDL_Rect checkSDL0(SDL_Rect a, SDL_Rect backGR) {
		if (a.w > backGR.w)a.w = backGR.w;
		if (a.h > backGR.h)a.h = backGR.h;
		if (a.x < 0)a.x = 0;
		if (a.y < 0)a.y = 0;
		if (a.x + a.w > backGR.w)a.x = backGR.w - a.w;
		if (a.y + a.h > backGR.h)a.y = backGR.h - a.h;
		return a;
	}

	pair<pair<double, double>, pair<double, double>> lan_double(pair<pair<double, double>, pair<double, double>> a, pair<pair<double, double>, pair<double, double>> now1, SDL_Rect backGR);

	bool check_man_hinh_Rect(pair<int, int> motion, SDL_Rect button);
private:
	double first1;
	double second1;
	SDL_Rect old;
};

