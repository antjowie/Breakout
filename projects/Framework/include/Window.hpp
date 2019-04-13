#pragma once

struct GLFWwindow;
class Window
{
public:
    GLFWwindow *m_window;
    int init(int width, int height);
};
