#include "speed.h"

int speed::runright(double TIMEnow, double TIMEold)
{

	run += g * pow(TIMEnow - TIMEold, 2) / 2 + SpeedX * (TIMEnow - TIMEold);

	SpeedX += g * (TIMEnow - TIMEold);
	SpeedX = min(SpeedX, 500.0);
	x = run;
	run -= int(run);

	return int(x);

}

int speed::down(double TIMEnow, double TIMEold)
{

	run1 += g2 * pow(TIMEnow - TIMEold, 2) / 2 + SpeedG * (TIMEnow - TIMEold);

	SpeedG += g2 * (TIMEnow - TIMEold);
	SpeedG = min(SpeedG, 500.0);
	x = run1;
	run1 -= int(run1);

	return int(x);
}

int speed::jumb()
{
	run1 = g1 * pow(0.01, 2) / 2;
	SpeedG = g1 * (0.01);
	return int(run1);
}