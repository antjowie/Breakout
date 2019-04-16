#include "InputHandler.hpp"
#include <GLFW/glfw3.h>

InputHandler::InputHandler(GLFWwindow *window) : m_window(window)
{
}

bool InputHandler::isKeyPressed(int key)
{
    return glfwGetKey(m_window, key);
}
