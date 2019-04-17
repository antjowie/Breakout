#pragma once

#include "Graphics.h"


class Game 
{
private:
	GLFWwindow * m_windowHandle;
	Graphics m_graphics;

	unsigned m_vao;

	void handleInput(double elapsedTime);
	void update(double elapsedTime);
	void render();

public:
	Game(int width, int height, const char * windowTitle);

	void run();
};