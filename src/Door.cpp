#pragma once

#include "Door.h"

Door::Door(const int row, const int col, const int board_row, const int board_col)
	:StaticObjects(row, col, board_row, board_col)
{
	m_Texture.loadFromFile("Door.pnj");
	m_Sprite.setTexture(m_Texture);
}

sf::Sprite Door::GetSprite()
{
	return m_Sprite;
}
