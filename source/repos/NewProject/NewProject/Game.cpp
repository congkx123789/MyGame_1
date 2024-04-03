#include "Game.h"

GameCharacter* mainplayer;

GameCharacter* testplayer;

MAP* background;

void My_Game::init(const char* tittle, int xrow, int ycolum, bool Full_Screen) {

	Uint32 FullScreen1 = 0;
	if (Full_Screen == 1) { FullScreen1 = SDL_WINDOW_FULLSCREEN; }
	// FULL SCREEN!
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(tittle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, xrow, ycolum, FullScreen1);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	cout << "SYSTEMS INITIALIZED!" << endl;

	Screen = { 0,0,xrow,ycolum };

	mainplayer = new GameCharacter("Controll.txt", renderer, 0, 0);
	testplayer = new GameCharacter("Controll.txt", renderer, 600, 0);

	background = new MAP("map.txt", renderer, Screen);

	cout << "LOADED IMAGE!" << endl;
}

void My_Game::render1()
{
	SDL_RenderClear(renderer);
	background->RenderCP();
	mainplayer->render1(background->VeX(), background->veY());

	testplayer->render1(background->VeX(), background->veY());
	SDL_RenderPresent(renderer);
}

bool My_Game::running1()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		return false;
	else if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_a:
			mainplayer->update('a', 1);
			break;
		case SDLK_d:
			mainplayer->update('d', 1);
			break;
		case SDLK_k:
			mainplayer->update('k', 1);
			break;
		default:
			break;
		}

	}
	else if (SDL_KEYUP == event.type) {
		switch (event.key.keysym.sym) {
		case SDLK_a:
			mainplayer->update('a', 0);
			break;
		case SDLK_d:
			mainplayer->update('d', 0);
			break;
		case SDLK_k:
			mainplayer->update('k', 0);
			break;
		default:
			break;
		}
	}
	return true;

}

void My_Game::analy()
{
	//backgournd
	background->updateVector(mainplayer->GetADD());
	background->update();

	//main
	mainplayer->check();
	mainplayer->resetSPE(background->coll(mainplayer->GetTA(), mainplayer->GetADD()));

	testplayer->check();
	testplayer->resetSPE(background->coll(testplayer->GetTA(), testplayer->GetADD()));
}

void My_Game::change()
{
	testplayer->GetTIME(TIMENOW);
	mainplayer->GetTIME(TIMENOW);
}

void My_Game::ALLold()
{
	testplayer->GetTIMEold();
	mainplayer->GetTIMEold();
}

void My_Game::return_All_time()
{
	mainplayer->GetTIME(TIMENOW);
	mainplayer->GetTIMEold();

	testplayer->GetTIME(TIMENOW);
	testplayer->GetTIMEold();
	background->GetScreen(Screen);
	//background->updateVector();
	//background->update();
}

void My_Game::Systems_Clear()
{
	delete mainplayer;
	delete testplayer;
	delete background;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "SYSTEMS DESTROYED!" << endl;
}