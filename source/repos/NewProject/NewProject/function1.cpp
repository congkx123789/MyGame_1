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

SDL_Rect function1::center(SDL_Rect little1, SDL_Rect huge,SDL_Rect BackGR)
{
    SDL_Rect b = huge;
    double a = huge.w - little1.w;
    a /= 2.0;
    b.x = little1.x - a;
    a = huge.h - little1.h;
    a /= 2.0;
    b.y = little1.y - a;
    b.x = max(b.x, 0);
    b.y = max(b.y, 0);
    b.x = min(b.x, BackGR.w - b.w);
    b.y = min(b.y, BackGR.h - b.h);
    return b;
}

SDL_Rect function1::nhan(SDL_Rect hazz, double ab)
{
    double a = hazz.x;
    hazz.x =lamtr(hazz.x * ab);
    a = hazz.w * ab;
    if (a == int(a)) hazz.w = a;
    else hazz.w = a + 2;
    a = hazz.h * ab;
    if (a == int(a)) hazz.h= a;
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
    return { basis.x + cong_SDL.x*2,basis.y + cong_SDL.y*2,cong_SDL.w*2,cong_SDL.h*2 };
}

bool function1::check_man_hinh_Rect(pair<int, int> motion, SDL_Rect button)
{
    if (motion.first >= button.x && motion.first <= button.x + button.w) 
        if (motion.second >= button.y && motion.second <= button.h + button.y)
            return 1;
    return 0;
}
