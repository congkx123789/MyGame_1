#include "Game.h"

GameCharacter* mainplayer;

GameCharacter* testplayer;

MAP* background;

function1 func11;
phantich *a123;

man_hinh_cho *Man_Hinh;

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
	//main
	mainplayer = new GameCharacter("all_text/Controll.txt", renderer,TIMENOW, 0, 0);
	testplayer = new GameCharacter("all_text/Controll.txt", renderer, TIMENOW, xrow/2, 0);
	//background
	background = new MAP("all_text/map.txt","all_text/Backgr.txt", renderer, Screen);

	//Set Man hinh cho
	Man_Hinh = new man_hinh_cho("all_text/man_hinh_cho.txt", renderer, Screen);

	//set phantich
	a123->set_all("all_text/alltext.txt","all_text/sat.txt"); delete a123;
	
	cout << "LOADED IMAGE!" << endl;
}

bool My_Game::man_hinh()
{
	return Man_Hinh->man_hinh_cho_1();
}

void My_Game::render1()
{
	SDL_RenderClear(renderer);

	background->RenderCP();
	if (ren) {
		mainplayer->render1(background->VeX());
		testplayer->render1(background->VeX());
	}
	else {
		testplayer->render1(background->VeX());
		mainplayer->render1(background->VeX());
	}
	SDL_RenderPresent(renderer);
}

void My_Game::analy()
{
	//backgournd
	background->updateVector(func11.gop(mainplayer->GetADD(), testplayer->GetADD()));
	background->update();

	//main
	mainplayer->check();
	mainplayer->resetSPE( background->coll(mainplayer->GetTA(), mainplayer->GetADD()) );
	
	testplayer->check();
	testplayer->resetSPE( background->coll(testplayer->GetTA(), testplayer->GetADD()) );
}

void My_Game::analy1()
{
	pair<SDL_Rect, pair<int, SDL_Rect>> main_Player = mainplayer->Set_Imae();
	pair<SDL_Rect, pair<int, SDL_Rect>> test_Player = testplayer->Set_Imae();

	bool b = func11.checkSDL1(test_Player.second.second , main_Player.first) == 0 ;
	bool a = func11.checkSDL1(main_Player.second.second, test_Player.first) == 0 ;

	if (a && b && main_Player.second.first>0 && test_Player.second.first>0) {
		ren = 1;
	}
	else if (a && main_Player.second.first > 0) {
		ren = 0; 
		testplayer->effect(main_Player.second.first);
	}
	else if (b && test_Player.second.first > 0) {
		ren = 1;
		mainplayer->effect(test_Player.second.first);
	}
	else {
		ren = 1;
	}
}

void My_Game::change()
{
	if (*TIMENOW - testplayer->getTIMEOLD() > 0.05){
		testplayer->GetTIMEold();
		mainplayer->GetTIMEold();
	}
	//testplayer->GetTIME(*TIMENOW);
	//mainplayer->GetTIME(*TIMENOW);
}

void My_Game::ALLold()
{
	testplayer->GetTIMEold();
	mainplayer->GetTIMEold();
}

void My_Game::return_All_time()
{
	mainplayer->GetTIMEold();
	testplayer->GetTIMEold();

	background->GetScreen(Screen);
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

bool My_Game::running1()
{
	int loai;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		return false;
	else if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			cout << event.key.keysym.sym << endl;
		case SDLK_a:
			mainplayer->update('a', 1);
			break;
		case SDLK_d:
			mainplayer->update('d', 1);
			break;
		case SDLK_k:
			mainplayer->update('k', 1);
			break;
		case SDLK_u:
			mainplayer->update('u', 1);
			break;
		case SDLK_j:
			mainplayer->update('j', 1);
			break;
		case SDLK_w:
			mainplayer->update('w', 1);
			break;
		case SDLK_s:
			mainplayer->update('s', 1);
			break;
		case SDLK_i:
			mainplayer->update('i', 1);
			break;
		case SDLK_LEFT:
			testplayer->update('a', 1);
			break;
		case SDLK_RIGHT:
			testplayer->update('d', 1);
			break;
		case 1073741914:
			testplayer->update('k', 1);
			break;
		case 1073741916:
			testplayer->update('u', 1);
			break;
		case 1073741913:
			testplayer->update('j', 1);
			break;
		case SDLK_UP:
			testplayer->update('w', 1);
			break;
		case SDLK_DOWN:
			testplayer->update('s', 1);
			break;
		case 1073741917:
			testplayer->update('i', 1);
			break;
		case 27:
			loai = Man_Hinh->man_hinh_cho_2(1);
			if (loai == 0)return false;
			else if (loai == 1) {
				mainplayer->return_ALL();
				testplayer->return_ALL();
			}
			event.type = SDL_KEYUP;
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
		case SDLK_u:
			mainplayer->update('u', 0);
			break;
		case SDLK_j:
			mainplayer->update('j', 0);
			break;
		case SDLK_w:
			mainplayer->update('w', 0);
			break;
		case SDLK_s:
			mainplayer->update('s', 0);
			break;
		case SDLK_i:
			mainplayer->update('i', 0);
			break;
		case SDLK_LEFT:
			testplayer->update('a', 0);
			break;
		case SDLK_RIGHT:
			testplayer->update('d', 0);
			break;
		case 1073741914:
			testplayer->update('k', 0);
			break;
		case 1073741916:
			testplayer->update('u', 0);
			break;
		case 1073741913:
			testplayer->update('j', 0);
			break;
		case SDLK_UP:
			testplayer->update('w', 0);
			break;
		case SDLK_DOWN:
			testplayer->update('s', 0);
			break;
		case 1073741917:
			testplayer->update('i', 0);
			break;
		default:
			break;
		}
	}
	if (mainplayer->runni() && testplayer->runni())	return true;
	else {
		if (Man_Hinh->man_hinh_cho_2(0) == 1) {
			mainplayer->return_ALL();
			testplayer->return_ALL();
			return 1;
		}
		else return 0;
	}
}
