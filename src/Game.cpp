#include "Game.hpp"

#include <iostream>
#include <GLFW/glfw3.h>

void Game::handleInput(double elapsedTime)
{
	if (m_inputHandler->isKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(m_graphics.m_window, GLFW_TRUE);
}

void Game::update(double elapsedTime)
{
}

void Game::render()
{
}

bool Game::init(int width, int height)
{
	bool error = false;
	error = m_graphics.init(width, height);
	if (!error)
	{
		std::cout << "Failed to load window\n";
		return false;
	}

	// Create input handler
	m_inputHandler = std::make_unique<InputHandler>(m_graphics.m_window);
	std::cout << "Game initialized success\n";
	return true;
}

void Game::run()
{
	glfwSetTime(1.f / 60.f);

	double totalTime = 0;
	double elapsedTime = 0;

	while (!glfwWindowShouldClose(m_graphics.m_window))
	{
		totalTime += glfwGetTime();
		elapsedTime = totalTime	- glfwGetTime();

		glfwPollEvents();
		glfwSwapBuffers(m_graphics.m_window);

		handleInput(elapsedTime);
		update(elapsedTime);
		render();
	}

}
