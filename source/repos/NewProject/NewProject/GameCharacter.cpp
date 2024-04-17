#include "GameCharacter.h"

function1 tien_ich;

map<SDL_Rect*, pair<phantich, speed>> input;

bool GameCharacter::ch(char check1)
{
	return input[sizePIC].first.find1(check1);
}

GameCharacter::GameCharacter(const char* file, SDL_Renderer* renderer, double* time, int x, int y)
{
	TIMEnow = time;
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
	readfile >> b;
	health_bar = func.Manager_Texture(b.c_str(), renderer);
	readfile.close();
	Address = { x,y,100,74 };
	sizePIC = new SDL_Rect({ 0,0,50,36 });
	testADD = Address;

	health = { 0,0,763,230 };
	addhealth = { x,0,500,32 };
	input[sizePIC].first.setALL(CharacterTex, TIMEnow);

	Address_old = Address;
}

void GameCharacter::check()
{
	testADD = Address;

	input[sizePIC].first.Charac();
	if (ch('a'))	testADD.x -= input[sizePIC].second.runright(*TIMEnow, TIMEold, 1000);
	if (ch('d'))	testADD.x += input[sizePIC].second.runright(*TIMEnow, TIMEold, 1000);
	if (ch('k'))	testADD.y += input[sizePIC].second.jumb(-230000);

	testADD.y += input[sizePIC].second.down(*TIMEnow, TIMEold, 10000);

	//if (ch('D'))	testADD.x += input[sizePIC].second.runright(*TIMEnow, TIMEold, 1500);
	//if (ch('A'))	testADD.x -= input[sizePIC].second.runright(*TIMEnow, TIMEold, 1500);
	//if (ch('K')) {
	//	input[sizePIC].second.resetG();
	//	testADD.y -= testADD.y += input[sizePIC].second.jumb(-20000);
	//}

}

void GameCharacter::resetSPE(SDL_Rect check)
{
	input[sizePIC].first.checkRECT(testADD, check);
	if (ch('d') == 0 && ch('a') == 0 && ch('A') == 0 && ch('D') == 0) input[sizePIC].second.resetX();



	if (input[sizePIC].first.Getspeedx())input[sizePIC].second.resetX();
	if (input[sizePIC].first.Getspeedg())input[sizePIC].second.resetG();

	Address = check;
}

void GameCharacter::render1(pair<SDL_Rect, double> Screen1)
{
	double a = HP / HPold;
	SDL_Rect ADD = { Address.x - Screen1.first.x, Address.y - Screen1.first.y, Address.w, Address.h };
	ADD = tien_ich.nhan(ADD, Screen1.second);
	SDL_Rect check = health;
	SDL_Rect check1 = addhealth;
	check.w *= a;
	check1.w *= a;
	SDL_RenderCopy(render, health_bar, &check, &check1);
	SDL_RenderCopy(render, input[sizePIC].first.reTEX(), sizePIC, &ADD);

}

void GameCharacter::effect(int a)
{
	input[sizePIC].first.new_charchec('+', 3);
	HP -= a * (*TIMEnow - TIMEold);
}

void GameCharacter::return_ALL()
{
	HP = HPold;
	Address = Address_old;
	input[sizePIC].first.return_ALL();
	input[sizePIC].second.resetX();
	input[sizePIC].second.resetG();
}

pair<SDL_Rect, pair<int, SDL_Rect>> GameCharacter::Set_Imae()
{
	pair<int, SDL_Rect> a = input[sizePIC].first.ret_Sat();
	a.second = tien_ich.congSDL(Address, a.second);
	return make_pair(Address, a);
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
