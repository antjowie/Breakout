#include "Game.hpp"

Game::~Game()
{
}

bool Game::init(GLFWwindow *window, InputHandler *inputHandler)
{
    m_window = window;
    m_inputHandler = inputHandler;

	return true;
}