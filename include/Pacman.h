#pragma once

#include <SFML/Graphics.hpp>

const float PACMAN_SPEED = 10.f;

enum Direction { Up, Down, Right, Left };

class Pacman
{
public:
    Pacman();
    void UpdateDirection(sf::Keyboard::Key key);
    sf::Vector2f DirectionToVector(Direction);
    void Move(sf::Time delta);
    sf::Sprite GetPacman();

private:
    int m_life = 3;
    int m_score = 0;
    sf::Texture m_Tpacman;
    sf::Sprite m_pacman;
    Direction m_direction;
    //Animation m_animation;
};