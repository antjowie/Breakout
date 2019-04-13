#include "Application.hpp"

#include <GLFW\glfw3.h>
#include <iostream>

int Application::init(int width, int height, std::unique_ptr<Game> &&game)
{
    int status = 0;
    m_window = std::make_unique<Window>();
    status = m_window->init(width, height);
    if (status != 0)
    {
        std::cout << "Error while generating window\n";
        return status;
    }

    m_game.swap(game);

    return 0;
}

void Application::run()
{
    while (glfwWindowShouldClose(m_window->m_window) == GLFW_FALSE)
    {
        glfwSwapBuffers(m_window->m_window);
        glfwPollEvents();
    }
}