#include "man_hinh_cho.h"
function1 func_check;
SDL_Event check_all;
man_hinh_cho::man_hinh_cho(const char* file, SDL_Renderer* render, SDL_Rect screen)
{
	Screen = screen;
	renderer = render;
	ifstream readfile(file);
	string a;
	readfile >> a;
	exit.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> exit.first.x >> exit.first.y >> exit.first.w >> exit.first.h;
	readfile >> a;
	start.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> start.first.x >> start.first.y >> start.first.w >> start.first.h;
	readfile >> a;
	resume.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> resume.first.x >> resume.first.y >> resume.first.w >> resume.first.h;
	readfile >> a;
	restart.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> restart.first.x >> restart.first.y >> restart.first.w >> restart.first.h;
	readfile >> a;
	Exit_2.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> Exit_2.first.x >> Exit_2.first.y >> Exit_2.first.w >> Exit_2.first.h;
	readfile >> a;
	background = func_check.Manager_Texture(a.c_str(), renderer);
}

void man_hinh_cho::render1()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, &Screen);
	SDL_RenderCopy(renderer, exit.second, NULL, &exit.first);
	SDL_RenderCopy(renderer, start.second, NULL, &start.first);
	SDL_RenderPresent(renderer);
}

void man_hinh_cho::render2(bool a)
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, &Screen);
	if (a)	SDL_RenderCopy(renderer, resume.second, NULL, &resume.first);
	SDL_RenderCopy(renderer, Exit_2.second, NULL, &Exit_2.first);
	SDL_RenderCopy(renderer, restart.second, NULL, &restart.first);
	SDL_RenderPresent(renderer);
}

bool man_hinh_cho::man_hinh_cho_1()
{
	while (1) {
		SDL_PollEvent(&check_all);
		render1();
		if (check_all.type == SDL_QUIT) return 0;
		if (check_all.button.button == SDL_BUTTON_LEFT || check_all.button.button == SDL_BUTTON_RIGHT) {
			if (func_check.check_man_hinh_Rect(make_pair(check_all.motion.x, check_all.motion.y), start.first))	return 1;
			if (func_check.check_man_hinh_Rect(make_pair(check_all.motion.x, check_all.motion.y), exit.first))	return 0;
		}
		SDL_Delay(20);
	}
}

int man_hinh_cho::man_hinh_cho_2(bool a)
{
	SDL_Event now;
	while (1) {
		SDL_PollEvent(&now);
		render2(a);
		if (now.type == SDL_QUIT) return 0;
		//if(now.type == SDL_MOUSEMOTION)
		if (now.button.button == SDL_BUTTON_LEFT || now.button.button == SDL_BUTTON_RIGHT) {

			if (func_check.check_man_hinh_Rect(make_pair(now.motion.x, now.motion.y), restart.first))		return 1;
			if (func_check.check_man_hinh_Rect(make_pair(now.motion.x, now.motion.y), Exit_2.first))			return 0;
			if (func_check.check_man_hinh_Rect(make_pair(now.motion.x, now.motion.y), resume.first) && a)	return -1;
		}
		SDL_Delay(20);
	}
}
