#include"function1.h"

int lamtr(double a) {


	if (a - int(a) > 0.5)
		a = int(a) + 1;
	else
		a = int(a);
	return a;
}

bool checkSDL(pair<double, double> check, double w, double h, SDL_Rect add)
{
	if (check.second + h <= add.y || check.first >= add.x + add.w || check.first + w <= add.x || check.second >= add.y + add.h)
		return true;
	return false;
}

bool dodai(pair<double, double> before, pair<double, double> after)
{
	double answer = pow(before.first - after.first, 2) + pow(before.second - after.second, 2);

	return answer > 0.05;
}

pair<double, double> tru(pair<double, double> before, pair<double, double> after)
{
	return make_pair(after.first - before.first, after.second - before.second);
}

pair<double, double> nhan(pair<double, double> before, double b)
{
	pair<double, double> ok = make_pair(before.first * b, before.second * b);
	return ok;
}

pair<double, double> cong(pair<double, double> before, pair<double, double> after)
{

	return make_pair(after.first + before.first, after.second + before.second);
}

pair<double, double> find(pair<double, double> before, pair<double, double> after, SDL_Rect add, double w, double h)
{
	pair<double, double> check = nhan(cong(before, after), 0.5);
	if (checkSDL(check, w, h, add))
	{

		if (dodai(check, after))
			return find(check, after, add, w, h);
		else
			return check;
	}
	else
	{

		if (dodai(before, check))
			return find(before, check, add, w, h);
		else
			return check;
	}
}

void function1::answer1(SDL_Rect add, double w, double h)
{
	pair<double, double> answer = find(make_pair(old.x, old.y), make_pair(first1, second1), add, w, h);
	first1 = answer.first;
	second1 = answer.second;
}

bool function1::checkDouble(double w, double h, SDL_Rect add)
{
	return checkSDL(make_pair(first1, second1), w, h, add);
}

pair<pair<double, double>, pair<double, double>> function1::center(pair<pair<double, double>, pair<double, double>> check, double w1, double h1, SDL_Rect BackGR)
{
	double w = BackGR.w, h = BackGR.h;
	pair<pair<double, double>, pair<double, double>> check1;
	double a = w1 - check.second.first;
	a /= 2.0;
	check1.first.first = check.first.first - a;

	a = h1 - check.second.second;
	a /= 2.0;
	check1.second.first = w1; check1.second.second = h1;
	check1.first.second = check.first.second - a;
	check1.first.first = max(check1.first.first, 0.0);
	check1.first.second = max(check1.first.second, 0.0);
	check1.first.first = min(check1.first.first, w - check1.second.first);
	check1.first.second = min(check1.first.second, h - check1.second.second);


	return check1;
}

SDL_Rect function1::nhan(SDL_Rect hazz, double ab)
{
	double a = hazz.x;
	hazz.x = lamtr(hazz.x * ab);
	a = hazz.w * ab;
	if (a == int(a)) hazz.w = a;
	else hazz.w = a + 2;
	a = hazz.h * ab;
	if (a == int(a)) hazz.h = a;
	else hazz.h = a + 2;
	hazz.y = lamtr(hazz.y * ab);
	return hazz;
}

double function1::chia(int a, int b)
{
	double a1 = a, b1 = b;
	return a1 / b1;
}

SDL_Rect function1::congSDL(SDL_Rect basis, SDL_Rect cong_SDL)
{
	return { basis.x + cong_SDL.x * 2,basis.y + cong_SDL.y * 2,cong_SDL.w * 2,cong_SDL.h * 2 };
}

pair<pair<double, double>, pair<double, double>> function1::lan_double(pair<pair<double, double>, pair<double, double>> a, pair<pair<double, double>, pair<double, double>> now1, SDL_Rect backGR)
{

	pair<pair<double, double>, pair<double, double>> chec;

	chec.first.first = min(a.first.first, now1.first.first);
	chec.first.second = min(a.first.second, now1.first.second);
	chec.second.first = max(a.second.first + a.first.first, now1.first.first + now1.second.first) - chec.first.first;
	chec.second.second = max(a.second.second + a.first.second, now1.first.second + now1.second.second) - chec.first.second;

	double w = chec.second.first, h = chec.second.second;
	if (16.0 / 9.0 > w / h) w = h / 9.0 * 16.0;    else h = w / 16.0 * 9.0;

	chec.first.first = a.first.first - now1.first.first;
	chec.second.first = now1.second.first + now1.first.first - a.second.first - a.first.first;
	chec.first.second = a.first.second - now1.first.second;
	chec.second.second = now1.second.second + now1.first.second - a.second.second - a.first.second;

	if (chec.first.first < 0 || chec.first.second < 0) {
		if (chec.first.first < 0)   chec.first.first += now1.first.first;
		else chec.first.first = now1.first.first;
		if (chec.first.second < 0)  chec.first.second += now1.first.second;
		else chec.first.second = now1.first.second;

	}
	else chec = now1;

	chec.second.first = w;
	chec.second.second = h;

	if (chec.first.first < 0)	chec.first.first = 0;
	if (chec.first.second < 0)  chec.first.second = 0;
	if (chec.first.first + chec.second.first > backGR.w)    chec.first.first = backGR.w - chec.second.first;
	if (chec.first.second + chec.second.second > backGR.h)  chec.first.second = backGR.h - chec.second.second;

	if (chec.second.first - a.second.first < 0.001)chec.second.first = a.second.first;
	if (chec.second.second - a.second.second < 0.001)chec.second.second = a.second.second;


	return chec;

}

bool function1::check_man_hinh_Rect(pair<int, int> motion, SDL_Rect button)
{
	if (motion.first >= button.x && motion.first <= button.x + button.w)
		if (motion.second >= button.y && motion.second <= button.h + button.y)
			return 1;
	return 0;
}