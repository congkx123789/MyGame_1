#include"function1.h"

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

