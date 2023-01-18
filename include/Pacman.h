#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Resources.h"

const float PACMAN_SPEED = 300.f;

class Pacman : public MovingObject
{
public:
    Pacman(const int , const int , const int , const int , Object );
    void UpdateDirection(sf::Vector2f);
    void Move(sf::Time);

private:
    //int m_life = 3;
    //int m_score = 0;
    Direction m_direction = Stay;
    //Animation m_animation;
};