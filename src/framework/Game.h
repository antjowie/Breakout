#pragma once

#include "Graphics.h"
#include "Scene.h"

#include <stack>
#include <memory>

class Game 
{
private:
	std::stack<std::unique_ptr<Scene>> m_scenes;
	std::unique_ptr<Graphics> m_graphics;
	
public:
	Game(std::unique_ptr<Graphics> graphics, std::unique_ptr<Scene> scene);

	void run();
};