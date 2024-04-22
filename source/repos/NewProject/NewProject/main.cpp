#include "Game.h"

My_Game* game = nullptr;

int main(int argc, char* argv[]) {

//	srand(time(NULL));

	game = new My_Game;

	Uint32 FPS = 60;

	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;

	int frameTime;

	game->init("Hello world", 1024, 576, 0);

	cout << "running" << endl;

	game->SetTime(SDL_GetTicks());
	game->return_All_time();
	if(game->man_hinh())
	while (game->running1()) {

		frameStart = SDL_GetTicks();
		
		game->change();
		
		game->analy();

		game->analy1();
		
		game->render1();

		game->ALLold();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

		game->SetTime(SDL_GetTicks());

	}

	game->Systems_Clear();
	
	return 0;
}
