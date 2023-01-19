#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object object)
    :MovingObject(row, col, board_row, board_col, object),
     m_state(std::make_unique<NormalPacman>())
{
    m_sprite.setOrigin((float)m_sprite.getTextureRect().height / 2,(float) m_sprite.getTextureRect().width / 2);
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
    m_last_location = m_sprite.getPosition();
    m_sprite.move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    
}

void Pacman::UpgradeToSuper()
{
    m_state.reset(new SuperPacmanState());
}

void Pacman::DowngradeToNormal()
{
    m_state.reset(new NormalPacman());
}

int Pacman::GetKeyCounter()
{
    return m_KeyCounter;
}

void Pacman::DecKeys()
{
    m_KeyCounter--;
}

void Pacman::SetLastLocation()
{
    m_sprite.setPosition(m_last_location);
}

void Pacman::HandleCollision(GameObject& game_object) 
{
    game_object.HandleCollision(*this);
}

void Pacman::HandleCollision(Pacman& pacman)
{
}

void Pacman::HandleCollision(Deamon& deamon)
{
    //m_state->handleDeamonCollision(m_KeyCounter, deamon, *this);
}

void Pacman::HandleCollision(Wall& wall)
{
    m_sprite.setPosition(m_last_location);
}

void Pacman::HandleCollision(Door& door)
{
    m_state->handleDoorCollision(m_KeyCounter, door, *this);
}

void Pacman::HandleCollision(Key& key)
{
    m_score += 7;
    m_KeyCounter++;
}

void Pacman::HandleCollision(Present& present)
{
    m_score += 5;
}

void Pacman::HandleCollision(Cookie& cookie)
{
    m_score += 2;
}
