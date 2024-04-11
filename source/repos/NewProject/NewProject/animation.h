#pragma once
#include"Game.h"
using namespace std;
class animation
{
public:

	int ans(double time);
	void setall(pair<bool, int> loop1, int n1, double time) { loop = loop1; n = n1; TIME = time; }
	void setdone() { checkdone = 1; }
	bool reDONE() { return checkdone; }

	int amination_basis(double time);

private:

	double TIME = 0.0;

	pair<bool, int> loop = make_pair(0, 0);

	int n;

	double now_N = 0.0;

	bool checkdone = 0;

	double TIMEDelay = 0.0;

};