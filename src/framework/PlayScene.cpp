#include "PlayScene.h"

#include <GLFW/glfw3.h>

void PlayScene::handleInput(double elapsedTime, const Graphics & graphics)
{
	if (glfwGetKey(graphics.windowHandle(),GLFW_KEY_ESCAPE) == GLFW_PRESS)
		m_shouldPop = true;
}

std::unique_ptr<Scene> PlayScene::update(double elapsedTime, double totalTime)
{
	return nullptr;
}

void PlayScene::draw()
{
	m_spriteRenderer.display();
}
