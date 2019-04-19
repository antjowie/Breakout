#pragma once
#include <vector>
#include <glm/vec2.hpp>

class Sprite;
class SpriteRenderer
{
private:
	unsigned m_program;
	unsigned m_vao;

	std::vector<glm::vec2> m_sprites;

public:
	SpriteRenderer();
	void addSprite(const Sprite &sprite);
	void display();
};