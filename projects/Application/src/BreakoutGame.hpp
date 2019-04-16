#pragma once
#include "Game.hpp"

class BreakoutGame : public Game
{
public:
	virtual bool onCreate() override final;

	virtual void handleInput(double elapsedTime) override final;
	virtual void update(double elapsedTime) override final;
	virtual void render() override final;
};