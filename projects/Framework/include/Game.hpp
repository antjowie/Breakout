#pragma once

struct GLFWwindow;

class Game
{
private:
	GLFWwindow *m_window;

	void handleInput(float elapsedTime);
	void update(float elapsedTime);
	void render();

public:
	int init(int width, int height);

	void run();
};