#include "Game.hpp"

#include <iostream>
#include <GLFW/glfw3.h>

void Game::handleInput(double elapsedTime)
{
	if (m_inputHandler.isKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(m_windowHandle, GLFW_TRUE);
}

void Game::update(double elapsedTime)
{
}

void Game::render()
{
}

Game::Game(int width, int height)
{
	m_windowHandle = m_graphics.createWindow(width,height);
	m_inputHandler.setWindowHandle(*m_windowHandle);
}

void Game::run()
{
	glfwSetTime(1.f / 60.f);

	double totalTime = 0.;
	double elapsedTime = 0.;

	while (!glfwWindowShouldClose(m_windowHandle))
	{
		totalTime += glfwGetTime();
		elapsedTime = totalTime	- glfwGetTime();

		glfwPollEvents();
		glfwSwapBuffers(m_windowHandle);

		handleInput(elapsedTime);
		update(elapsedTime);
		render();
	}
}
