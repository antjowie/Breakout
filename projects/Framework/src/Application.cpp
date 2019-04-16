#include "Application.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Application::~Application()
{
    glfwTerminate();
}

bool Application::init(int width, int height, std::unique_ptr<Game> &&game)
{
    // Create window
    // ---
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, "Breakout", nullptr, nullptr);
    if (m_window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glViewport(0, 0, width, height);

    // Create input handler
    m_inputHandler = std::make_unique<InputHandler>(m_window);

    m_game.swap(game);
    m_game->init(m_window, m_inputHandler.get());

    glfwSetTime(0);
    return true;
}

void Application::run()
{
    double lastTime = glfwGetTime();
    double elapsedTime = lastTime - glfwGetTime();

    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

        m_game->handleInput(elapsedTime);
        m_game->update(elapsedTime);

        m_game->render();
    }
}