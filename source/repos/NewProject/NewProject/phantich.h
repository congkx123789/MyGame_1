#pragma once
#include"Game.h"
using namespace std;
class phantich
{
public:

	void checkDOWN(char down);

	void checkUP(char up);

	bool find1(char key) { return output[key]; }

	bool Get_Jumb() { return jumb; }

	bool Getspeedx() { return speedx; }

	bool Getspeedg() { return speedg; }

	void checkRECT(SDL_Rect old, SDL_Rect check);

	void setALL(map<char, pair<int, SDL_Texture**>>* CharacterTex1, double* TIME) {
		CharacterTex = CharacterTex1;
		TIMENOW = TIME;
	}

	void Charac();

	SDL_Texture* reTEX() { return mainTex; }

private:
	double* TIMENOW;
	bool jumb = 0;
	bool speedx = 0;
	bool speedg = 0;
	int oldg = 0;
	bool chieu = 1;

	bool jumb2 = 0;

	map<char, bool> input;
	map<char, bool> output;

	SDL_Texture* mainTex;
	Uint32 test;

	map<char, pair<int, SDL_Texture**>>* CharacterTex = nullptr;

	char* oldchar = nullptr;
	char* oldchar1 = nullptr;
	char* oldchar2 = nullptr;

};

