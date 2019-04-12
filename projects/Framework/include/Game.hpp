#pragma once

class Game
{
private:

public:
    void init();

    void handleInput(float elapsedTime);
    void update(float elapsedTime);
    void render();
};