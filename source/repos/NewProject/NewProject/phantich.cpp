#include "phantich.h"

void phantich::checkDOWN(char down)
{
	if (down != 'k') {
		if (down == 'a') {
			chieu = 0;
			input[down] = 1;
			if (input['d']) {
				speedx = 1;
				input.erase('d');
			}
		}
		else if (down == 'd') {
			chieu = 1;
			input[down] = 1;
			if (input['a']) {
				speedx = 1;
				input.erase('a');
			}
		}
	}
	else if (jumb == 1) {
		input[down] = 1;
	}

}

void phantich::checkUP(char up)
{
	input.erase(up);
}

bool phantich::find1(char key)
{
	if (key == 'k' && input[key]) {
		if (jumb) {
			test = SDL_GetTicks();
			return 1;
		}
		return 0;
	}

	return input[key];
}

void phantich::checkRECT(SDL_Rect old, SDL_Rect check)
{
	if (old.x != check.x) {
		speedx = 1;

	}
	else speedx = 0;
	cout << old.y << " " << check.y << endl;
	if (old.y != check.y && check.y == oldg) {

		if (old.y > check.y)
			jumb = 1;
		speedg = 1;
	}
	else {
		jumb = 0;
		speedg = 0;
	}

	oldg = check.y;
}

char phantich::checkinput()
{
	if (SDL_GetTicks() - test < 500)jumb_animation = 1;
	else jumb_animation = 0;

	if (jumb_animation && chieu)return'k';
	else if (jumb_animation && chieu == 0)return '!';
	else if (input['a'])return'a';
	else if (input['d'])return 'd';
	else if (chieu) return '+';
	else return '-';
}