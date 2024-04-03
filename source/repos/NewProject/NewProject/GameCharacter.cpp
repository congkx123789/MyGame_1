#include "GameCharacter.h"

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

		for (int i = 0; i < n1; i++) {
			readmyfile >> b;

			(*CharacterTex)[key].second[i] = func.Manager_Texture(b.c_str(), renderer);

		}
		readmyfile.close();
	}
	readfile.close();
	Address = { x,y,37,50 };
	sizePIC = new SDL_Rect({ 7,6,28,30 });
}

void GameCharacter::check()
{
	testADD = Address;

	if (input[sizePIC].first.find1('a')) {
		testADD.x -= input[sizePIC].second.runright(TIMEnow, TIMEold);
		//cout << "a" << endl;
	}
	if (input[sizePIC].first.find1('d')) {
		testADD.x += input[sizePIC].second.runright(TIMEnow, TIMEold);
		//cout << "d" << endl;
	}
	if (input[sizePIC].first.find1('k')) {
		testADD.y += input[sizePIC].second.jumb();
		//cout << "k" << endl;
	}
	//input[sizePIC].first.checkUP('k');
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

void GameCharacter::render1(int x, int y)
{

	SDL_Rect ADD = Address;
	ADD.x -= x;
	ADD.y -= y;
	char key = input[sizePIC].first.checkinput();
	SDL_RenderCopy(render, (*CharacterTex)[key].second[int(TIMEnow * double(8.33)) % (*CharacterTex)[key].first], sizePIC, &ADD);

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