#include "phantich.h"
map<map<char, pair<int, SDL_Texture**>>*, map<char, animation>> animtion_Char;


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
	if (old.x != check.x) {
		speedx = 1;

	}
	else speedx = 0;
	speedg = 0;
	if (old.y != check.y) {
		if (old.y > check.y) {
			jumb = 1; oldg = check.y;
		}
		speedg = 1;
	}
	if (oldg != check.y) {
		jumb = 0;
	}
}

void phantich::Charac()
{
	int Tex;

	output.clear();

	if (oldchar) {
		Tex = animtion_Char[CharacterTex][*oldchar].ans(*TIMENOW);
		if (animtion_Char[CharacterTex][*oldchar].reDONE()) {
			animtion_Char[CharacterTex].erase(*oldchar);
			oldchar = nullptr;
		}
		else {
			mainTex = (*CharacterTex)[*oldchar].second[Tex];
			return;
		}
	}

	if (oldchar == nullptr) {
		if (chieu) {
			if (jumb) {
				jumb2 = 0;
				if (input['w'] && input['j']) {
					animtion_Char[CharacterTex]['x'].setall(make_pair(0, 0), (*CharacterTex)['x'].first, *TIMENOW);
					oldchar = new char('x');
				}
				else if (input['s'] && input['j']) {
					animtion_Char[CharacterTex]['z'].setall(make_pair(0, 0), (*CharacterTex)['z'].first, *TIMENOW);
					oldchar = new char('z');
				}
				else if (input['j']) {
					animtion_Char[CharacterTex]['c'].setall(make_pair(0, 0), (*CharacterTex)['c'].first, *TIMENOW);
					oldchar = new char('c');
				}
			}
			else {
				if (input['i']) {
					animtion_Char[CharacterTex]['6'].setall(make_pair(0, 0), (*CharacterTex)['6'].first, *TIMENOW);
					oldchar = new char('6');
				}
				else if (input['u'] && input['w']) {
					animtion_Char[CharacterTex]['2'].setall(make_pair(0, 0), (*CharacterTex)['2'].first, *TIMENOW);
					oldchar = new char('2');
				}
				else if (input['u'] && input['s']) {
					animtion_Char[CharacterTex]['4'].setall(make_pair(0, 0), (*CharacterTex)['4'].first, *TIMENOW);
					oldchar = new char('4');
				}
				else if (input['u']) {
					animtion_Char[CharacterTex]['0'].setall(make_pair(0, 0), (*CharacterTex)['0'].first, *TIMENOW);
					oldchar = new char('0');
				}
			}
		}
		else {
			if (jumb) {
				jumb2 = 0;
				if (input['w'] && input['j']) {
					animtion_Char[CharacterTex]['X'].setall(make_pair(0, 0), (*CharacterTex)['X'].first, *TIMENOW);
					oldchar = new char('X');
				}
				else if (input['s'] && input['j']) {
					animtion_Char[CharacterTex]['Z'].setall(make_pair(0, 0), (*CharacterTex)['Z'].first, *TIMENOW);
					oldchar = new char('Z');
				}
				else if (input['j']) {
					animtion_Char[CharacterTex]['C'].setall(make_pair(0, 0), (*CharacterTex)['C'].first, *TIMENOW);
					oldchar = new char('C');
				}
			}
			else {
				if (input['i']) {
					animtion_Char[CharacterTex]['7'].setall(make_pair(0, 0), (*CharacterTex)['7'].first, *TIMENOW);
					oldchar = new char('7');
				}
				else if (input['u'] && input['w']) {
					animtion_Char[CharacterTex]['3'].setall(make_pair(0, 0), (*CharacterTex)['3'].first, *TIMENOW);
					oldchar = new char('3');
				}
				else if (input['u'] && input['s']) {
					animtion_Char[CharacterTex]['5'].setall(make_pair(0, 0), (*CharacterTex)['5'].first, *TIMENOW);
					oldchar = new char('5');
				}
				else if (input['u']) {
					animtion_Char[CharacterTex]['1'].setall(make_pair(0, 0), (*CharacterTex)['1'].first, *TIMENOW);
					oldchar = new char('1');
				}
			}
		}
	}

	output['a'] = input['a'];
	output['d'] = input['d'];

	if (oldchar) {
		if ((*oldchar == '3' || *oldchar == '1' || *oldchar == '0' || *oldchar == '2') && jumb2) {
			output['k'] = 1;
			jumb2 = 0;
		}
		mainTex = (*CharacterTex)[*oldchar].second[0];
		return;
	}

	if (oldchar1) {
		Tex = animtion_Char[CharacterTex][*oldchar1].ans(*TIMENOW);
		if (animtion_Char[CharacterTex][*oldchar1].reDONE() || jumb) {
			animtion_Char[CharacterTex].erase(*oldchar1);
			oldchar1 = nullptr;
		}
		else {
			mainTex = (*CharacterTex)[*oldchar1].second[Tex];
			return;
		}
	}

	if (input['k'] && jumb) {
		output['k'] = 1;
		jumb2 = 1;
		if (chieu) {
			animtion_Char[CharacterTex]['k'].setall(make_pair(0, 0), (*CharacterTex)['k'].first, *TIMENOW);
			oldchar1 = new char('k');
		}
		else {
			animtion_Char[CharacterTex]['K'].setall(make_pair(0, 0), (*CharacterTex)['K'].first, *TIMENOW);
			oldchar1 = new char('K');
		}
		mainTex = (*CharacterTex)[*oldchar1].second[0];
		return;
	}

	if (input['a']) {
		chieu = 0;
		if (*oldchar2 != 'a') {
			animtion_Char[CharacterTex]['a'].setall(make_pair(0, 0), (*CharacterTex)['a'].first, *TIMENOW);
			oldchar2 = new char('a');
		}
	}
	else if (input['d']) {
		chieu = 1;
		if (*oldchar2 != 'd') {
			animtion_Char[CharacterTex]['d'].setall(make_pair(0, 0), (*CharacterTex)['d'].first, *TIMENOW);
			oldchar2 = new char('d');
		}
	}
	else {
		if (oldchar2) {
			if (*oldchar2 == 'd' || *oldchar2 == 'a') {
				if (chieu) {
					animtion_Char[CharacterTex]['+'].setall(make_pair(0, 0), (*CharacterTex)['+'].first, *TIMENOW);
					oldchar2 = new char('+');
				}
				else {
					animtion_Char[CharacterTex]['-'].setall(make_pair(0, 0), (*CharacterTex)['-'].first, *TIMENOW);
					oldchar2 = new char('-');

				}
			}
		}
		else {
			animtion_Char[CharacterTex]['+'].setall(make_pair(0, 0), (*CharacterTex)['+'].first, *TIMENOW);
			oldchar2 = new char('+');
		}
	}

	mainTex = (*CharacterTex)[*oldchar2].second[animtion_Char[CharacterTex][*oldchar2].amination_basis(*TIMENOW)];
	return;
}
