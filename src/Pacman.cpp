#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object object)
    :MovingObject(row, col, board_row, board_col, object)
{
    m_sprite.setOrigin(m_sprite.getTextureRect().height / 2, m_sprite.getTextureRect().width / 2);
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
    switch (m_direction)
    {
    case Up:
        m_sprite.setRotation(-90);
        break;
    case Down:
        m_sprite.setRotation(90);
        break;
    case Right:
        m_sprite.setRotation(0);
        break;
    case Left:
        m_sprite.setRotation(180);
        break;
    case Stay:
        break;
    default:
        break;
    }
    m_last_locatiom = m_location;
    m_sprite.move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    
}
