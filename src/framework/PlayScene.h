#pragma once
#include "Scene.h"
#include "gameplay/Sprite.h"
#include "gameplay/SpriteRenderer.h"

#include <vector>

class PlayScene : public Scene
{
private:
	std::vector<std::unique_ptr<Sprite>> m_sprites;
	SpriteRenderer m_spriteRenderer;

public:
	virtual void handleInput(double elapsedTime, const Graphics &graphics) override final;
	virtual std::unique_ptr<Scene> update(double elapsedTime, double totalTime) override final;
	virtual void draw() override final;

};