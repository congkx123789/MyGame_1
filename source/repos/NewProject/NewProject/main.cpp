#include "Game.h"

My_Game* game = nullptr;

int main(int argc, char* argv[]) {

	//	srand(time(NULL));

	game = new My_Game;

	Uint32 FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;

	int frameTime;

	game->init("Hello world", 1200, 800, 0);

	cout << "running" << endl;

	game->SetTime(SDL_GetTicks());

	game->return_All_time();

	while (game->running1()) {

		frameStart = SDL_GetTicks();
		game->change();

		game->analy();

		game->render1();

		game->ALLold();

		frameTime = SDL_GetTicks() - frameStart;

		//		 SDL_Delay(5000);

		if (frameDelay > frameTime) {

			SDL_Delay(frameDelay - frameTime);
			//https://www.youtube.com/watch?v=jzasDqPmtPI&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=5 
			// I learn FPS in this video
		}
		game->SetTime(SDL_GetTicks());

	}

	game->Systems_Clear();

	return 0;
}
