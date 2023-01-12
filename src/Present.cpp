#pragma once

#include "Present.h"

Present::Present(const int row, const int col, const int board_row, const int board_col)
	:StaticObjects(row, col, board_row, board_col)
{
	m_Texture.loadFromFile("Present.pnj");
	m_Sprite.setTexture(m_Texture);
}

sf::Sprite Present::GetSprite()
{
	return m_Sprite;
}
