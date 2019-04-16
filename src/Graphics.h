#pragma once

struct GLFWwindow;
class Graphics
{
public:
	~Graphics();

	GLFWwindow *m_window;

	bool init(int width, int height);
};