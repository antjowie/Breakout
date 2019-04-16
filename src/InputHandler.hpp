#pragma once

struct GLFWwindow;
class InputHandler
{
private:
    GLFWwindow *m_window;

public:
    InputHandler(GLFWwindow *window);

    bool isKeyPressed(int key);
};