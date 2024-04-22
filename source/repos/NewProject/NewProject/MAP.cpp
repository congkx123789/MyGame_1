#include "MAP.h"

function1 func1;

map<int, vector<SDL_Rect>> mapGame;

map<int, vector<SDL_Rect>> mapG;

SDL_Rect add;

MAP::MAP(const char* tittle, const char* file, SDL_Renderer* render, SDL_Rect screen, double* time)
{
	TIME = time;
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

		wall[i] = func1.Manager_Texture(s.c_str(), renderer);
	}
	int a;
	for (int i = 0; i < n; i++) {
		readfile >> a;

		for (int j = 0; j < a; j++) {

			readfile >> add.x >> add.y;

			mapGame[i].push_back(add);
		}
	}
	readfile.close();
	ifstream file1(file);
	file1 >> s;

	BackGround = func1.Manager_Texture(s.c_str(), renderer);
	file1 >> BackGR.w >> BackGR.h;

	file1.close();
}//0

pair<pair<double, double>, pair<double, double>> MAP::giam_dan(pair<pair<double, double>, pair<double, double>> a, pair<pair<double, double>, pair<double, double>> b, double time)
{

	double x = abs(a.first.first - b.first.first);
	double y = abs(a.first.second - b.first.second);
	double w = abs(a.first.first + a.second.first - b.first.first - b.second.first); if (w < 0.00001)w = 0;
	double h = abs(a.first.second + a.second.second - b.first.second - b.second.second); if (h < 0.00001) h = 0;

	double a1 = 960.0;
	double b1 = 540.0;

	//double a1 = 640.0;
	//double b1 = 360.0;
	if (time_check <= 0) {
		if (x != 0) {
			a.first.first += min(x, a1 / (x + w) * x * time);
			a.second.first -= min(x, a1 / (x + w) * x * time);
		}

		if (w != 0) a.second.first -= min(w, a1 / (x + w) * w * time);

		if (h != 0) a.second.second -= min(h, b1 / (y + h) * h * time);

		if (y != 0) {
			a.first.second += min(y, b1 / (y + h) * y * time);
			a.second.second -= min(y, b1 / (y + h) * y * time);
		}
	}

	else time_check -= time;

	return a;
}

void MAP::Get_now_Screen(pair<pair<double, double>, pair<double, double>> a)
{
	if (TIMEold == 0)	TIMEold = *TIME;
	if (now.w == 0)		now_double = a;
	pair<pair<double, double>, pair<double, double>> check = now_double;
	now_double = func1.lan_double(a, now_double, BackGR);

	if (abs(check.second.first - now_double.second.first) > 0.0001 && now_double.second.first > check.second.first) time_check = 0.2;

	now_double = giam_dan(now_double, a, *TIME - TIMEold);


	now = { int(now_double.first.first),int(now_double.first.second),int(now_double.second.first),int(now_double.second.second) };
	return;
}

void MAP::updateVector(SDL_Rect gop)
{
	SDL_Rect gop1 = { gop.x - 32,gop.y - 32,gop.w + 64,gop.h + 64 };
	gop1 = func1.checkSDL0(gop1, BackGR);

	double w = gop1.w, h = gop1.h;
	if (16.0 / 9.0 > w / h) w = h / 9.0 * 16.0;
	else h = w / 16.0 * 9.0;
	if (h < Screen.h * 2.0 / 3.0) { w = Screen.w * 2.0 / 3.0; h = Screen.h * 2.0 / 3.0; }

	pair<pair<double, double>, pair<double, double>> a;

	a = func1.center(make_pair(make_pair(gop1.x, gop1.y), make_pair(gop1.w, gop1.h)), w, h, BackGR);

	Get_now_Screen(a);

	docheck = func1.chia(Screen.w, now.w);
}

void MAP::update()
{

	int a = 0;
	for (auto i : mapGame) {
		add.w = i.second[0].w;
		add.h = i.second[0].h;
		for (int j = 0; j < i.second.size(); j++) {
			if (i.second[j].x + 32 > now.x && i.second[j].x < now.x + now.w) {
				if (i.second[j].y + 32 > now.y && i.second[j].y < now.y + now.h) {
					mapG[a].push_back(i.second[j]);
				}
			}
		}
		a++;
	}
}

SDL_Rect MAP::coll(SDL_Rect check, SDL_Rect old)
{
	SDL_Rect a1 = func1.gop(old, check);
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
	a1.x = max(a1.x, 0);
	a1.y = max(a1.y, 0);
	a1.x = min(a1.x, BackGR.w - a1.w);
	a1.y = min(a1.y, BackGR.h - a1.h);
	return a1;
}//2

void MAP::RenderCP()
{
	SDL_RenderCopy(renderer, BackGround, &now, NULL);

	SDL_Rect red;
	int a = 0;
	for (auto i : mapG) {
		for (int j = 0; j < i.second.size(); j++) {
			red = func1.nhan({ i.second[j].x - now.x, i.second[j].y - now.y, i.second[j].w, i.second[j].h }, docheck);

			SDL_RenderCopy(renderer, wall[a], NULL, &red);
		}
		a++;
	}
	TIMEold = *TIME;
	mapG.clear();
}//3
