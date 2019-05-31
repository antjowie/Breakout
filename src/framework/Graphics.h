#pragma once

struct GLFWwindow;
class Graphics
{
private:
	GLFWwindow *m_window;

public:
	Graphics(int width, int height, const char* title = "GLFW window");
	~Graphics();

	GLFWwindow * windowHandle() const; 
};