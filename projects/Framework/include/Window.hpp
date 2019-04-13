#pragma once

struct GLFWwindow;
class Window
{
public:
    ~Window();

    GLFWwindow *m_window;
    int init(int width, int height);
};
