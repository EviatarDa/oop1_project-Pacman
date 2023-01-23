#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object object)
    :MovingObject(row, col, board_row, board_col, object),
     m_state(std::make_unique<NormalPacman>())
{
    m_sprite.setOrigin((float)m_sprite.getTextureRect().height / 2, (float)m_sprite.getTextureRect().width / 2);
    for (int sound = MINUS_LIFE ; sound <= EAT ;sound++)
    {
        m_Sounds[sound].setBuffer(Resources::instance().GetSound((Sound)sound));
    }
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
    m_sprite.setColor(sf::Color::Red);
    m_state.reset(new SuperPacmanState());
}

void Pacman::DowngradeToNormal()
{
    m_sprite.setColor(sf::Color::Yellow);
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

void Pacman::DecLife()
{
    m_life--;
}

void Pacman::SetLastLocation()
{
    m_sprite.setPosition(m_last_location);
}

void Pacman::SetLife()
{
    m_life--;
    m_Sounds[MINUS_LIFE].play();
}

int Pacman::GetLife()
{
    return m_life;
}

int Pacman::GetScore()
{
    return m_score;
}

int Pacman::GetKeys()
{
    return m_KeyCounter;
}

int Pacman::GetEatten()
{
    return m_EattenCookies;
}

void Pacman::SetCookies()
{
    m_EattenCookies = 0;
}

void Pacman::UpdateState(bool freeze , int& added_time)
{
    if (m_PaClock.getElapsedTime() > m_SuperTime + sf::seconds(20))
    {
        DowngradeToNormal();
    }

    if (m_PaClock.getElapsedTime() > m_FreezeTime + sf::seconds(5))
    {
        m_freeze = false;
    }
    added_time = m_time_collected;
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
    m_state->handleDeamonCollision(m_life, deamon, *this);
    deamon.HandleCollision(*this);
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

void Pacman::HandleCollision(SuperPresent&)
{
    m_SuperTime = m_PaClock.getElapsedTime();
    m_score += 5;
    UpgradeToSuper();
}

void Pacman::HandleCollision(AddTime&)
{
    m_time_collected += 20;
    m_score += 5;
}

void Pacman::HandleCollision(Freeze&)
{
    m_FreezeTime = m_PaClock.getElapsedTime();
    m_score += 5;
    m_freeze = true;
}

void Pacman::HandleCollision(AddLife&)
{
    m_score += 5;
    m_life++;
}

void Pacman::HandleCollision(Cookie& cookie)
{
    m_score += 2;
    m_EattenCookies++;
    m_Sounds[EAT].play();
}
