#include <iostream>
#include "Game.h"
#include <SDL.h>
//#include <SDL_mixer.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include <imgui/imgui.h>
//#include <glm/glm.hpp>
//#include <sol/sol.hpp>


int main(int argc, char* argv[]) {

	Game game;

	game.Initialize();
	game.Run();
	game.Destroy();
	
	return 0;
}