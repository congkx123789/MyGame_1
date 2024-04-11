#include "GameCharacter.h"

function1 tien_ich;

map<SDL_Rect*, pair<phantich, speed>> input;

GameCharacter::GameCharacter(const char* file, SDL_Renderer* renderer, int x, int y)
{
	CharacterTex = new map<char, pair <int, SDL_Texture**>>();
	render = renderer;
	int n, n1;
	string a, b;
	char key;
	function1 func;

	ifstream readfile(file);
	readfile >> n;

	for (int j = 0; j < n; j++) {

		readfile >> a;
		readfile >> key;
		ifstream readmyfile(a.c_str());
		readmyfile >> n1;

		(*CharacterTex)[key].second = new SDL_Texture * [n1];
		(*CharacterTex)[key].first = n1;
		cout << key << endl;
		for (int i = 0; i < n1; i++) {
			readmyfile >> b;

			(*CharacterTex)[key].second[i] = func.Manager_Texture(b.c_str(), renderer);

		}
		readmyfile.close();
	}

	readfile.close();
	Address = { x,y,100,74 };
	sizePIC = new SDL_Rect({ 0,0,50,36 });

	input[sizePIC].first.setALL(CharacterTex, &TIMEnow);
}

void GameCharacter::check()
{
	testADD = Address;

	input[sizePIC].first.Charac();

	if (input[sizePIC].first.find1('a'))
		testADD.x -= input[sizePIC].second.runright(TIMEnow, TIMEold);
	if (input[sizePIC].first.find1('d'))
		testADD.x += input[sizePIC].second.runright(TIMEnow, TIMEold);
	if (input[sizePIC].first.find1('k'))
		testADD.y += input[sizePIC].second.jumb();
	testADD.y += input[sizePIC].second.down(TIMEnow, TIMEold);

}

void GameCharacter::resetSPE(SDL_Rect check)
{
	input[sizePIC].first.checkRECT(testADD, check);
	if (input[sizePIC].first.find1('d') == 0 && input[sizePIC].first.find1('a') == 0)
		input[sizePIC].second.resetX();

	if (input[sizePIC].first.Getspeedx())input[sizePIC].second.resetX();
	if (input[sizePIC].first.Getspeedg())input[sizePIC].second.resetG();

	Address = check;

}

void GameCharacter::render1(pair<SDL_Rect, double> Screen1)
{

	SDL_Rect ADD = { Address.x - Screen1.first.x, Address.y - Screen1.first.y, Address.w, Address.h };
	ADD = tien_ich.nhan(ADD, Screen1.second);
	SDL_RenderCopy(render, input[sizePIC].first.reTEX(), sizePIC, &ADD);
}

void GameCharacter::update(char key, bool check)
{

	if (check)
		input[sizePIC].first.checkDOWN(key);
	else
		input[sizePIC].first.checkUP(key);

	if (input[sizePIC].first.Getspeedx())input[sizePIC].second.resetX();
	if (input[sizePIC].first.Getspeedg())input[sizePIC].second.resetG();

}