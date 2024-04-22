#pragma once
#include"Game.h"
using namespace std;
class phantich
{
public:
	void setALL(map<char, pair<int, SDL_Texture**>>* CharacterTex1, double* TIME) {
		CharacterTex = CharacterTex1;
		TIMENOW = TIME;
	}
	void set_all(const char* file, const char* file2);
	bool Getspeedx() { return speedx; }
	bool Getspeedg() { return speedg; }
	void check(char a, int b);
	bool check1();
	bool Get_Jumb() { return jumb; }

	void  new_charchec(char a, int b);

	void checkDOWN(char down);

	void checkUP(char up);

	bool find1(char key) { return output[key]; }

	void checkRECT(SDL_Rect old, SDL_Rect check);
	void Charac();
	void set_mainTex(char a, int b);
	char effect_out() {
		if (chieu) return 'h';
		else return 'H';
	}
	pair<int, SDL_Rect> ret_Sat() { return Sat_th; }
	SDL_Texture* reTEX() { return mainTex; }

	void return_ALL() {
		jumb = 0;
		speedx = 0;
		speedg = 0;
		oldg = 0;
		chieu = 1;
		input.clear();

		oldchar = nullptr;
		oldchar1 = nullptr;
		oldchar2 = nullptr;
	}

private:
	double* TIMENOW;
	bool jumb = 0;
	bool speedx = 0;
	bool speedg = 0;
	int oldg = 0;
	bool chieu = 1;
	map<char, bool> input;

	map<char, bool> output;
	SDL_Texture* mainTex;
	map<char, pair<int, SDL_Texture**>>* CharacterTex = nullptr;
	pair<int, SDL_Rect> Sat_th;

	char* oldchar = nullptr;
	char* oldchar1 = nullptr;
	char* oldchar2 = nullptr;

};

