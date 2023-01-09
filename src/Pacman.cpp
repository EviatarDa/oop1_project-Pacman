#pragma once

#include "Pacman.h"

Pacman::Pacman()
{
	m_Tpacman.loadFromFile("Pacman.png");
	m_pacman.setTexture(m_Tpacman);
    m_pacman.scale(sf::Vector2f((sf::VideoMode::getDesktopMode().width - 520) * 0.07 / m_pacman.getTextureRect().width,
        (sf::VideoMode::getDesktopMode().width - 520) * 0.07 / m_pacman.getTextureRect().width));
}

void Pacman::UpdateDirection(sf::Keyboard::Key key)
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
        break;
    }
}

sf::Vector2f Pacman::DirectionToVector(Direction direction)
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

void Pacman::Move()//sf::Time delta)
{
    //m_pacman.move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    m_pacman.move(DirectionToVector(m_direction) * PACMAN_SPEED);

}

sf::Sprite Pacman::GetPacman()
{
    return m_pacman;
}
