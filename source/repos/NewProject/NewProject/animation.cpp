#include "animation.h"

int animation::ans(double time)
{

	if (loop.first && int(now_N) == loop.second) {
		TIME = time;
		return loop.second;
	}
	now_N += (time - TIME) * 8.33;

	TIME = time;
	if (int(now_N) >= n) {
		checkdone = 1;
	}
	return min(n - 1, int(now_N));
}

int animation::amination_basis(double time)
{
	now_N += (time - TIME) * 8.33;
	TIME = time;
	return int(now_N) % n;
}
