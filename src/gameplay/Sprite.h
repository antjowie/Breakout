#pragma once
#include "SpriteRenderer.h"

#include <glm/vec2.hpp>

class Sprite
{
public:
	glm::vec2 m_pos;

	Sprite(const glm::vec2 &pos = { 0,0 });
	void move(const glm::vec2 &movement);
	void draw(SpriteRenderer &renderer) const;
};