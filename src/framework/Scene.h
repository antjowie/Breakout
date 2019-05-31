#pragma once
#include "Graphics.h"
#include <memory>

class Game;
class Scene
{
protected:
	friend Game;
	bool m_shouldPop;
	bool m_shouldExit;

public:
	Scene();

	virtual void onCreate(Graphics &graphics);
	virtual void onDestroy();

	virtual void handleInput(double elapsedTime, const Graphics &graphics) = 0;
	virtual std::unique_ptr<Scene> update(double elapsedTime, double totalTime) = 0;
	virtual void draw() = 0;
};