#pragma once

#include "MovingObject.h"

MovingObject::MovingObject(const int row, const int col, const int board_row, const int board_col, Object object)
	:GameObject(row, col, board_row, board_col, object)
{
}

sf::Vector2f MovingObject::DirectionToVector(Direction direction)
{
    switch (direction)
    {
    case Direction::Up:
        return { 0, -1 };
    case Direction::Down:
        return { 0, 1 };
    case Direction::Right:
        return { 1, 0 };
    case Direction::Left:
        return { -1, 0 };
    default:
        return { 0, 0 };
    }
}

sf::Vector2f MovingObject::OppositeVector(Direction direction)
{
    switch (direction)
    {
    case Direction::Up:
        return { 0, 1 };
    case Direction::Down:
        return { 0, -1 };
    case Direction::Right:
        return { -1, 0 };
    case Direction::Left:
        return { 1, 0 };
    default:
        return { 0, 0 };
    }
}

void MovingObject::SetToFirstLocation()
{
    m_sprite.setPosition(m_first_location);
}
