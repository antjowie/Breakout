#pragma once
#include "Game.hpp"

class BreakoutGame : public Game
{
public:
    virtual bool init() override final;

    virtual void handleInput(float elapsedTime) override final;
    virtual void update(float elapsedTime) override final;
    virtual void render() override final;
};