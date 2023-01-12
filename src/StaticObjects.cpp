#pragma once

#include "StaticObjects.h"


StaticObjects::StaticObjects(const int row, const int col, const int board_row, const int board_col)
	:m_location((float)((1400 - board_col * 50.f) / 2 + (col * 50.f)),
				(float)((800 - board_row * 50.f) / 2 + (row * 50.f)))
{
}

const sf::Vector2f StaticObjects::GetLocation() const
{
	return m_location;
}
