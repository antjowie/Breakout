#pragma once

#include "Game.hpp"
#include "InputHandler.hpp"

#include <memory>

struct GLFWwindow;

class Application
{
private:
    GLFWwindow *m_window;
    std::unique_ptr<Game> m_game;
    std::unique_ptr<InputHandler> m_inputHandler;

public:
    ~Application();

    bool init(int width, int height, std::unique_ptr<Game> &&game);
    void run();
};