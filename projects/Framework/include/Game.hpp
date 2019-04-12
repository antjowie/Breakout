#pragma once

class Game
{
private:
public:
    int init();

    void handleInput(float elapsedTime);
    void update(float elapsedTime);
    void render();
};