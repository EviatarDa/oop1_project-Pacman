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

void Pacman::UpdateDeamonsDirection(sf::Vector2f)
{
}

void Pacman::Move(sf::Time delta)
{
    this->GetSprite().move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
}
