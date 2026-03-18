#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Game::Game()
{
	std::cout << "Game Constructor Called!" << std::endl;
	isRunning = false;
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

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	windowWidth = displayMode.w;
	windowHight = displayMode.h;

	window = SDL_CreateWindow (
			"Retina Engine",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			windowWidth,
			windowHight,
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cerr << "SDL_Renderer Error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	isRunning = true;

}

void Game::Setup()
{

}

void Game::Run()
{
	Setup();

	while (isRunning)
	{
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{

		case SDL_QUIT:

			isRunning = false;
			break;

		case SDL_KEYDOWN:

			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			break;
		}
	}
}

void Game::Update ()
{

}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);

	SDL_RenderClear(renderer);
	/*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect = { 10 , 10, 100, 100 };
	SDL_RenderFillRect(renderer, &rect);*/

	SDL_Surface* surface = IMG_Load("assets/images/tank-tiger-right.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_Rect destRect = { 100, 100, 64, 64 };
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
	SDL_DestroyTexture(texture);


	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}
