#include "BreakoutGame.hpp"
#include "InputHandler.hpp"

#include <GLFW/glfw3.h>

bool BreakoutGame::onCreate()
{
	return true;
}

void BreakoutGame::handleInput(double elapsedTime)
{
	if (m_inputHandler->isKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(m_window, true);
}

void BreakoutGame::update(double elapsedTime)
{
}

void BreakoutGame::render()
{
}
