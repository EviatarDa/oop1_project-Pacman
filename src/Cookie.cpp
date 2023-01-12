#pragma once

#include "Cookie.h"

Cookie::Cookie(const int row, const int col, const int board_row, const int board_col)
	:StaticObjects(row, col, board_row, board_col)
{
	m_Texture.loadFromFile("Cookie.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.scale(0.15, 0.15);
}

sf::Sprite Cookie::GetSprite()
{
	return m_Sprite;
}
