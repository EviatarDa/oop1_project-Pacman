#pragma once

#include "StaticObjects.h"




//const sf::Vector2f StaticObjects::GetLocation() const
//{
//	return m_location;
//}

StaticObjects::StaticObjects(const int row, const int col, const int board_row, const int board_col, Object object)
	:GameObject(row, col, board_row, board_col, object)
{

}
