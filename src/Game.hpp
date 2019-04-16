#pragma once

#include "InputHandler.hpp"
#include <memory>
#include "Graphics.h"

class Game 
{
private:
	Graphics m_graphics;
	std::unique_ptr<InputHandler> m_inputHandler;

	void handleInput(double elapsedTime);
	void update(double elapsedTime);
	void render();

public:
	bool init(int width, int height);

	void run();
};