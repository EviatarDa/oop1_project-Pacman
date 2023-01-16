#pragma once

#include "GameObject.h"

GameObject::GameObject(const int row, const int col, const int board_row, const int board_col, Object object)
	:m_location((float)((1400 - board_col * 50.f) / 2 + (col * 50.f)),
		(float)((800 - board_row * 50.f) / 2 + (row * 50.f)))
{
	m_sprite.setTexture(Resources::instance().GetGameObject(object));
	m_sprite.setPosition(m_location);
	m_sprite.scale(0.125, 0.125);
}

sf::Sprite& GameObject::GetSprite()
{
	return m_sprite;
}
