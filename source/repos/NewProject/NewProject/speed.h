#pragma once
#include"Game.h"
class speed
{
public:

	int runright(double TIMEnow, double TIMEold);

	int down(double TIMEnow, double TIMEold);

	int jumb();

	void resetG() { SpeedG = 0; }

	void resetX() { SpeedX = 0; }

private:

	double SpeedG = 0;

	double SpeedX = 0;

	double run = 0;

	double x = 0;

	double g = 1500;

	double g2 = 10000;

	double g1 = -200000;
};

