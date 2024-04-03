#include "speed.h"

int speed::runright(double TIMEnow, double TIMEold)
{

	run = g * pow(TIMEnow - TIMEold, 2) / 2 + SpeedX * (TIMEnow - TIMEold);

	SpeedX += g * (TIMEnow - TIMEold);
	SpeedX = min(SpeedX, 500.0);

	return int(run);

}

int speed::down(double TIMEnow, double TIMEold)
{

	run = g2 * pow(TIMEnow - TIMEold, 2) / 2 + SpeedG * (TIMEnow - TIMEold);

	SpeedG += g2 * (TIMEnow - TIMEold);
	SpeedG = min(SpeedG, 1000.0);
	return int(run);
}

int speed::jumb()
{
	run = g1 * pow(0.01, 2) / 2;
	SpeedG = g1 * (0.01);
	return int(run);
}
