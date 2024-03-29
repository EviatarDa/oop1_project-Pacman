#pragma once

#include "Pacman.h"

Pacman::Pacman(const int row, const int col, const int board_row, const int board_col, Object object)
    :MovingObject(row, col, board_row, board_col, object),
     m_state(std::make_unique<NormalPacman>()) //make first normal pacman
{
    //init pacman sounds
    for (int sound = MINUS_LIFE ; sound <= SUPER_PACMAN_SOUND;sound++)
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
    //rotate the pacman correspondingly
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
    //move
    m_last_location = m_sprite.getPosition();
    m_sprite.move(DirectionToVector(m_direction) * delta.asSeconds() * PACMAN_SPEED);
    
}

void Pacman::UpgradeToSuper()
{
    m_sprite.setColor(sf::Color::Red);
    m_state.reset(new SuperPacmanState());
    m_Sounds[SUPER_PACMAN_SOUND].play();
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
    //20 sec to be super pacman
    if (m_PaClock.getElapsedTime() > m_SuperTime + sf::seconds(20))
    {
        DowngradeToNormal();
    }

    // 5 sec to be freeze
    if (m_PaClock.getElapsedTime() > m_FreezeTime + sf::seconds(5))
    {
        m_freeze = false;
    }
    added_time = m_time_collected;
}

void Pacman::SetLife(int life)
{
    m_life = life;
}

void Pacman::SetScore(int score)
{
    m_score = score; 
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
    //the corrent state will decide what to do
    m_state->handleDeamonCollision(m_life, deamon, *this);
    deamon.HandleCollision(*this);
}

void Pacman::HandleCollision(Wall& wall)
{
    m_sprite.setPosition(m_last_location);
}

void Pacman::HandleCollision(Door& door)
{
    //the corrent state will decide what to do
    m_state->handleDoorCollision(m_KeyCounter, door, *this, m_Sounds[DOOR_SOUND]);
}

void Pacman::HandleCollision(Key& key)
{
    m_score += 7;
    m_KeyCounter++;
    m_Sounds[KEY_SOUND].play();
}

void Pacman::HandleCollision(SuperPresent&)
{
    //start counting from now
    m_SuperTime = m_PaClock.getElapsedTime();
    m_score += 5;
    UpgradeToSuper();
}

void Pacman::HandleCollision(AddTime&)
{
    m_time_collected += 20;
    m_score += 5;
    m_Sounds[CLOCK_SOUND].play();
}

void Pacman::HandleCollision(Freeze&)
{
    //start counting from now
    m_FreezeTime = m_PaClock.getElapsedTime();
    m_score += 5;
    m_freeze = true;
    m_Sounds[FREEZE_SOUND].play();
}

void Pacman::HandleCollision(AddLife&)
{
    m_score += 5;
    m_life++;
    m_Sounds[EXTRA_LIFE].play();
}

void Pacman::HandleCollision(Cookie& cookie)
{
    m_score += 2;
    m_EattenCookies++;
    m_Sounds[EAT].play();
}
