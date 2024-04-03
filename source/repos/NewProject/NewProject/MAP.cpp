#include "MAP.h"

function1 func1;

map<int, vector<SDL_Rect>> mapGame;

map<int, vector<SDL_Rect>> mapG;

SDL_Rect add;

MAP::MAP(const char* tittle, SDL_Renderer* render, SDL_Rect screen)
{
	add.w = 32;
	add.h = 32;
	renderer = render;
	Screen = screen;
	ifstream readfile(tittle);
	int n;// so loai tuong
	readfile >> n;
	wall = new SDL_Texture * [n];
	string s;
	for (int i = 0; i < n; i++) {

		readfile >> s;// tuong
		cout << s << endl;
		wall[i] = func1.Manager_Texture(s.c_str(), renderer);
	}

	int a;

	for (int i = 0; i < n; i++) {
		readfile >> a;
		cout << a << endl;
		for (int j = 0; j < a; j++) {

			readfile >> add.x >> add.y;

			mapGame[i].push_back(add);
		}

	}
	readfile.close();
}//0

void MAP::RenderCP()
{
	SDL_Rect red;
	int a = 0;
	for (auto i : mapG) {
		for (int j = 0; j < i.second.size(); j++) {
			red = i.second[j];
			red.x -= x;
			red.y -= y;
			SDL_RenderCopy(renderer, wall[a], NULL, &red);
		}
		a++;
	}
	mapG.clear();
}//3

void MAP::updateVector(SDL_Rect old)
{
	if (old.x >= 0 && old.x <= Screen.w / 2)x = 0;
	else x = old.x - Screen.w / 2;
	if (old.y >= Screen.h / 2 && old.y <= Screen.h)y = 0;
	else y = old.y - Screen.h / 2;
}

SDL_Rect MAP::coll(SDL_Rect check, SDL_Rect old)
{
	SDL_Rect a1 = { min(check.x,old.x),min(check.y,old.y),check.w + abs(check.x - old.x),check.h + abs(check.y - old.y) };
	vector<SDL_Rect> ok;
	for (auto i : mapG) {
		for (int j = 0; j < i.second.size(); j++) {
			if (func1.checkSDL1(a1, i.second[j]) == 0)
				ok.push_back(i.second[j]);
		}
	}
	a1 = old;

	func1.setDouble_AndOld(check.x, check.y, a1);
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}

	func1.lamtron();
	a1.x = func1.reDoubleF();
	a1.y = func1.reDoubleS();

	func1.setDouble_AndOld(a1.x, check.y, a1);
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}
	func1.lamtron();
	a1.y = func1.reDoubleS();

	func1.setDouble_AndOld(check.x, a1.y, a1);
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}

	func1.lamtron();
	a1.x = func1.reDoubleF();
	if (a1.x < 0)a1.x = 0;
	if (a1.y > Screen.h)a1.y = 0;
	return a1;
}//2

void MAP::update()
{
	add.w = 32;
	add.h = 32;
	int a = 0;
	for (auto i : mapGame) {
		add.w = i.second[0].w;
		add.h = i.second[0].h;
		for (int j = 0; j < i.second.size(); j++) {
			//if (i.second[j].x + 32 > Screen.x + x && i.second[j].x < Screen.x + Screen.w + x)
			//{
			//	if (i.second[j].y + 32 > Screen.y + y && i.second[j].y < Screen.y + Screen.h + y) {
			add.x = i.second[j].x;
			add.y = i.second[j].y;
			mapG[a].push_back(add);
			//	}
			//}
		}
		a++;
	}
}
