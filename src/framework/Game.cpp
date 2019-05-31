#include "Game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

Game::Game(std::unique_ptr<Graphics> graphics, std::unique_ptr<Scene> scene):
	m_graphics(graphics.release())
{
	m_scenes.push(std::move(scene));
	m_scenes.top()->onCreate(*m_graphics);
}

void Game::run()
{
	glfwSetTime(1. / 60.);

	double totalTime = 0.;
	double elapsedTime = 0.;
	
	glClearColor(0.4f, 0.4f, 0.8f, 1.f);
	do 
	{
		// Time
		elapsedTime = glfwGetTime() - totalTime;
		if (elapsedTime > 1.)
			elapsedTime = 1. / 60.;
		totalTime += elapsedTime;

		// Input and update
		m_scenes.top()->handleInput(elapsedTime, *m_graphics);
		auto newScene{ m_scenes.top()->update(elapsedTime, totalTime) };

		// Render
		glClear(GL_COLOR_BUFFER_BIT);
		m_scenes.top()->draw();

		// GLFW stuff
		glfwSwapBuffers(m_graphics->windowHandle());
		glfwPollEvents();

		// Update scene stack
		if (glfwWindowShouldClose(m_graphics->windowHandle()))
		{
			while (!m_scenes.empty())
				m_scenes.pop();
		}
		else if (newScene)
		{
			m_scenes.push(std::move(newScene));
		}
		else if (m_scenes.top()->m_shouldExit)
		{
			while (!m_scenes.empty())
				m_scenes.pop();
		}
		else if (m_scenes.top()->m_shouldPop)
		{
			m_scenes.pop();
		}
	} while (!m_scenes.empty());
}