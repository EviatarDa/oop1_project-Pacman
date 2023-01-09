#pragma once

#include <SFML/Graphics.hpp>

const float PACMAN_SPEED = 300.f;

enum Direction { Up, Down, Right, Left, Stay };

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
    Direction m_direction = Stay;
    //Animation m_animation;
};