#include "Game.h"
#include <SDL.h>
#include <iostream>

Game::Game()
{
	std::cout << "Game Constructor Called!" << std::endl;
}

Game::~Game()
{
	std::cout << "Game Destructor Called!" << std::endl;
}

void Game::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow (
			"Retina Engine",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			800,
			600,
			SDL_WINDOW_SHOWN );

	if (!window)
	{
		std::cerr << "SDL_Window Error: " << SDL_GetError() << std::endl;
		//SDL_Quit();
		return;
	}


	// The Params in SDL_CreateRenderer are:
	// 1st param:- Window,
	// 2nd param :- Index of the rendering driver to initialize (eg: -1 in this case picks the defualt display driver to display),
	// 3rd parm :- and flags for the renderer

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
		std::cerr << "SDL_Renderer Error: " << SDL_GetError() << std::endl;
		return;
	}

}

void Game::Run()
{
	/*while (true)
	{
		ProcessInput();
		Update();
		Render();
	}*/
}

void Game::ProcessInput()
{

}

void Game::Update ()
{

}

void Game::Render()
{

}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}
