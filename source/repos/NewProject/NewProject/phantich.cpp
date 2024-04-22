#include "phantich.h"
map<map<char, pair<int, SDL_Texture**>>*, map<char, animation>> animtion_Char;

map<char, pair<bool, pair<int, int>>> key;

map<char, map<int, pair<int, SDL_Rect>>> Sat_thuong;
map<char, map<int, pair<int, SDL_Rect>>> in_Sat;

void phantich::set_all(const char* file, const char* file2)
{
	ifstream readfile(file);
	int n;
	readfile >> n;
	pair<bool, pair<int, int>> a;
	char a1;
	while (n--) {
		readfile >> a1;
		readfile >> a.first >> a.second.first >> a.second.second;
		key[a1] = a;
	}
	readfile.close();
	ifstream read(file2);
	read >> n;
	int a2;
	int n1;
	pair<int, SDL_Rect> b;

	while (n--)
	{
		read >> n1; // char a1
		read >> a1;
		while (n1--)
		{
			read >> a2;
			read >> b.first >> b.second.x >> b.second.y >> b.second.w >> b.second.h;
			Sat_thuong[a1][a2] = b;
		}
	}
}

void phantich::set_mainTex(char a, int b)
{
	mainTex = (*CharacterTex)[a].second[b];
	Sat_th = Sat_thuong[a][b];
	return;
}

void phantich::check(char a, int b)
{
	bool fin = 0;
	if (animtion_Char[CharacterTex][a].reDONE() || (b == 1 && jumb)) fin = 1;
	if(oldchar)
	if (input['x'])fin = 1;
	if (fin) {
		animtion_Char[CharacterTex].erase(a);
		switch (b) {
		case 0:
			oldchar = nullptr;
			break;
		case 1:
			oldchar1 = nullptr;
			break;
		default:
			break;
		}
	}

}

bool phantich::check1()
{
	if (oldchar)
		if ((*oldchar == '7' || *oldchar == '6') && jumb)return 1;
	if (oldchar1)
		if ((*oldchar1 == 'k' || *oldchar1 == 'K') && jumb)return 1;
	return 0;
}

void phantich::new_charchec(char a, int b)
{
	switch (b) {
	case 0:
		animtion_Char[CharacterTex][a].setall(key[a], (*CharacterTex)[a].first, *TIMENOW);
		oldchar = new char(a);
		break;
	case 1:
		animtion_Char[CharacterTex][a].setall(key[a], (*CharacterTex)[a].first, *TIMENOW);
		oldchar1 = new char(a);
		break;
	case 2:

		animtion_Char[CharacterTex][a].setall(key[a], (*CharacterTex)[a].first, *TIMENOW);
		oldchar2 = new char(a);
		break;
	case 3:
		if (chieu) {
			animtion_Char[CharacterTex]['h'].setall(key['h'], (*CharacterTex)['h'].first, *TIMENOW);
			oldchar = new char('h');
		}
		else {
			animtion_Char[CharacterTex]['H'].setall(key['H'], (*CharacterTex)['H'].first, *TIMENOW);
			oldchar = new char('H');
		}
		break;
	default:
		break;
	}
}

void phantich::checkDOWN(char down)
{
	if (down != 'k') {
		if (down == 'a') {
			if (input['d']) {
				speedx = 1;
				input.erase('d');
			}
		}
		else if (down == 'd') {
			if (input['a']) {
				speedx = 1;
				input.erase('a');
			}
		}
		input[down] = 1;
	}
	else if (jumb == 1) {
		input[down] = 1;
	}

}

void phantich::checkUP(char up)
{
	input.erase(up);
}

void phantich::checkRECT(SDL_Rect old, SDL_Rect check)
{
	if (old.x != check.x) speedx = 1;
	else speedx = 0;
	speedg = 0;
	if (old.y != check.y) {
		if (old.y > check.y) {
			jumb = 1; oldg = check.y;
		}
		speedg = 1;
	}
	if (oldg != check.y) jumb = 0;
}

void phantich::Charac()
{
	int Tex;
	output.clear();

	if (oldchar) {
		Tex = animtion_Char[CharacterTex][*oldchar].ans(*TIMENOW);
		check(*oldchar, 0);
		if (oldchar) {
			if (check1())	animtion_Char[CharacterTex][*oldchar].setloop1();
			set_mainTex(*oldchar, Tex);
			return;
		}
	}

	if (oldchar == nullptr) {
		if (chieu) {
			if (jumb) {
				if (input['w'] && input['j']) new_charchec('x', 0);
				else if (input['s'] && input['j']) new_charchec('z', 0);
				else if (input['j']) new_charchec('c', 0);
			}
			else {
				if (input['i']) new_charchec('6', 0);
				else if (input['u'] && input['w']) new_charchec('2', 0);

				else if (input['u']) new_charchec('0', 0);
			}
		}
		else {
			if (jumb) {
				if (input['w'] && input['j']) new_charchec('X', 0);
				else if (input['s'] && input['j']) new_charchec('Z', 0);
				else if (input['j']) new_charchec('C', 0);
			}
			else {
				if (input['i']) new_charchec('7', 0);
				else if (input['u'] && input['w']) new_charchec('3', 0);
				else if (input['u']) new_charchec('1', 0);
			}
		}
	}

	if (oldchar) {
		set_mainTex(*oldchar, 0);
		return;
	}
	output['a'] = input['a'];
	output['d'] = input['d'];
	if (oldchar1) {
		Tex = animtion_Char[CharacterTex][*oldchar1].ans(*TIMENOW);
		check(*oldchar1, 1);
		if (oldchar1) {
			if (check1())	animtion_Char[CharacterTex][*oldchar1].setloop1();
			set_mainTex(*oldchar1, Tex);
			return;
		}
	}

	if (input['k'] && jumb) {
		output['k'] = 1;
		if (chieu) new_charchec('k', 1);
		else new_charchec('K', 1);
		set_mainTex(*oldchar1, 0);
		return;
	}

	if (input['a']) {
		chieu = 0;
		if (*oldchar2 != 'a') new_charchec('a', 2);
	}
	else if (input['d']) {
		chieu = 1;
		if (*oldchar2 != 'd') new_charchec('d', 2);
	}
	else {
		if (oldchar2) {
			if (*oldchar2 == 'd' || *oldchar2 == 'a') {
				if (chieu) new_charchec('+', 2);
				else new_charchec('-', 2);
			}
		}
		else new_charchec('+', 2);
	}

	if (oldchar2) {
		Tex = animtion_Char[CharacterTex][*oldchar2].amination_basis(*TIMENOW);
		set_mainTex(*oldchar2, Tex);
	}
	return;
}
