#include "framework/Game.h"
#include "framework/PlayScene.h"

#include <iostream>

int main() 
{	
	std::unique_ptr<Graphics> graphics;
	std::unique_ptr<Scene> scene;
	try
	{
	graphics = std::make_unique<Graphics>(1280, 720, "Breakout");
	scene = std::make_unique<PlayScene>();
	}
	catch (const char * message)
	{
		std::cout << "Failed to run game: " << message << '\n';

	}
	
	Game game(std::move(graphics),std::move(scene));
	game.run();
	return 0;
}