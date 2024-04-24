#include "man_hinh_cho.h"
function1 func_check;

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
	menu.second = func_check.Manager_Texture(a.c_str(), renderer);
	cout << a << endl;
	readfile >> menu.first.x >> menu.first.y >> menu.first.w >> menu.first.h;
	readfile >> a;
	cout << a << endl;
	tutorial.second = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> tutorial.first.x >> tutorial.first.y >> tutorial.first.w >> tutorial.first.h;
	readfile >> a;
	tutorial_image = func_check.Manager_Texture(a.c_str(), renderer);
	readfile >> a;
	background = func_check.Manager_Texture(a.c_str(), renderer);
	readfile.close();
}

void man_hinh_cho::render_tuto()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderCopy(renderer, menu.second, NULL, &menu.first);
	SDL_RenderCopy(renderer, tutorial_image, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void man_hinh_cho::render1()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderCopy(renderer, exit.second, NULL, &exit.first);
	SDL_RenderCopy(renderer, tutorial.second, NULL, &tutorial.first);
	SDL_RenderCopy(renderer, start.second, NULL, &start.first);
	SDL_RenderPresent(renderer);
}

void man_hinh_cho::render2(bool a)
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, &Screen);
	if (a)	SDL_RenderCopy(renderer, resume.second, NULL, &resume.first);
	SDL_RenderCopy(renderer, Exit_2.second, NULL, &Exit_2.first);
	SDL_RenderCopy(renderer, tutorial.second, NULL, &tutorial.first);
	SDL_RenderCopy(renderer, restart.second, NULL, &restart.first);
	SDL_RenderPresent(renderer);
}

bool man_hinh_cho::man_hinh_tuto()
{
	SDL_Event now_1;
	while (1) {
		SDL_PollEvent(&now_1);
		render_tuto();
		if (now_1.type == SDL_QUIT) return 1;

		if (now_1.button.type == SDL_MOUSEBUTTONUP) 
			if (func_check.check_man_hinh_Rect(make_pair(now_1.motion.x, now_1.motion.y), menu.first)) break;;
		SDL_Delay(20);
	}

	return 0;
}

bool man_hinh_cho::man_hinh_cho_1()
{
	SDL_Event now_2;
	while (1) {
		SDL_PollEvent(&now_2);
		render1();
		if (now_2.type == SDL_QUIT) return 0;
		if (now_2.button.type == SDL_MOUSEBUTTONUP) {
			if (func_check.check_man_hinh_Rect(make_pair(now_2.motion.x, now_2.motion.y), start.first))	return 1;
			if (func_check.check_man_hinh_Rect(make_pair(now_2.motion.x, now_2.motion.y), exit.first))	return 0;
			if (func_check.check_man_hinh_Rect(make_pair(now_2.motion.x, now_2.motion.y), tutorial.first)) if (man_hinh_tuto()) return 0;
			now_2.motion.x = -2;
		}
		SDL_Delay(20);
	}
}

int man_hinh_cho::man_hinh_cho_2(bool a)
{
	SDL_Event now_3;
	while (1) {
		SDL_PollEvent(&now_3);
		render2(a);
		if (now_3.type == SDL_QUIT) return 0;
		if (now_3.button.type == SDL_MOUSEBUTTONUP) {
			if (func_check.check_man_hinh_Rect(make_pair(now_3.motion.x, now_3.motion.y), restart.first))		return 1;
			if (func_check.check_man_hinh_Rect(make_pair(now_3.motion.x, now_3.motion.y), Exit_2.first))			return 0;
			if (func_check.check_man_hinh_Rect(make_pair(now_3.motion.x, now_3.motion.y), resume.first) && a)	return -1;
			if (func_check.check_man_hinh_Rect(make_pair(now_3.motion.x, now_3.motion.y), tutorial.first)) if (man_hinh_tuto()) return 0;
			now_3.motion.x = -2;
		}
		
		SDL_Delay(20);
	}
}
