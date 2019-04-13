#pragma once

class Game
{
public:
	virtual bool init() = 0;

	virtual void handleInput(float elapsedTime) = 0;
	virtual void update(float elapsedTime) = 0;
	virtual void render() = 0;
};