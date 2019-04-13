#pragma once
#include <memory>
#include "Window.hpp"
#include "Game.hpp"

class Application
{
private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Game> m_game;

public:
    int init(int width, int height, std::unique_ptr<Game> &&game);
    void run();
};