#pragma once

#include "GameObject.h"

GameObject::GameObject(const int row, const int col, const int board_row, const int board_col, Object object)
	:m_last_location((float)(((1400 - board_col * 50.f) / 2 + (col * 50.f)) + 25.f),
					 (float)(((800 - board_row * 50.f) / 2 + (row * 50.f)) + 25.f)),
	m_first_location(m_last_location)
{
	m_sprite.setTexture(Resources::instance().GetGameObject(object));
	m_sprite.setPosition(m_last_location);
	m_sprite.scale(0.125, 0.125);
	m_sprite.setOrigin((float)m_sprite.getTextureRect().height / 2, (float)m_sprite.getTextureRect().width / 2);
}

sf::Sprite& GameObject::GetSprite()
{
	return m_sprite;
}

bool GameObject::CheckCollision(const GameObject& game_object) const
{
	if (&game_object == this)
		return false;
	return m_sprite.getGlobalBounds().intersects(game_object.m_sprite.getGlobalBounds());
}

const bool GameObject::GetIsCollide() const
{
	return m_IsCollide;
}