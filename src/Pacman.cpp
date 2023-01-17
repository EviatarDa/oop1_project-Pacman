#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object objec)
    :MovingObject(row, col, board_row, board_col, objec)
{
}

void Pacman::UpdateDirection(sf::Vector2f PacLocation)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_direction = Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_direction = Right;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_direction = Up;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_direction = Down;
    }
    else
    {
        m_direction = Stay;
    }
}

void Pacman::Move(sf::Time delta)
{
    //this->GetSprite().move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    m_last_locatiom = m_location;
    m_sprite.move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    
}
