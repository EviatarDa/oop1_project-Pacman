#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object objec)
    :MovingObject(row, col, board_row, board_col, objec)
{
}

void Pacman::UpdateDirection(sf::Keyboard::Key key, sf::Vector2f PacLocation)
{
    switch (key)
    {
    case sf::Keyboard::Left:
        m_direction = Left;
        break;

    case sf::Keyboard::Right:
        m_direction = Right;
        break;

    case sf::Keyboard::Up:
        m_direction = Up;
        break;

    case sf::Keyboard::Down:
        m_direction = Down;
        break;

    default:
        m_direction = Stay;
        break;
    }
}

//sf::Vector2f Pacman::DirectionToVector(Direction direction)
//{
//    switch (direction)
//    {
//    case Direction::Up:
//        return { 0, -1 };
//    case Direction::Down:
//        return { 0, 1 };
//    case Direction::Right:
//        return { 1, 0 };
//    case Direction::Left:
//        return { -1, 0 };
//    default:
//        return { 0, 0 };
//    }
//}

void Pacman::Move(sf::Time deltaa)
{
    auto delta = m_game_clock.restart();

    this->GetSprite().move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
}

//sf::Sprite Pacman::GetPacman()
//{
//    return m_pacman;
//}
