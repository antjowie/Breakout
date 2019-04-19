#include "Sprite.h"

Sprite::Sprite(const glm::vec2 & pos):
	m_pos(pos)
{
}

void Sprite::move(const glm::vec2 & movement)
{
	m_pos += movement;
}

void Sprite::draw(SpriteRenderer & renderer) const
{
	renderer.addSprite(*this);
}