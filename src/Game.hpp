#pragma once

#include "InputHandler.hpp"
#include "Graphics.hpp"

class Game 
{
private:
	GLFWwindow * m_windowHandle;

	Graphics m_graphics;
	InputHandler m_inputHandler;

	void handleInput(double elapsedTime);
	void update(double elapsedTime);
	void render();

public:
	Game(int width, int height);

	void run();
};