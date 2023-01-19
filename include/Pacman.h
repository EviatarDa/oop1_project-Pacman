#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Resources.h"

const float PACMAN_SPEED = 150;

class Pacman : public MovingObject
{
public:
    Pacman(const int , const int , const int , const int , Object );
    void UpdateDirection(sf::Vector2f);
    void Move(sf::Time);

    virtual void HandleCollision(GameObject&)override;
    virtual void HandleCollision(Pacman&)override;
    virtual void HandleCollision(Deamon&)override;
    virtual void HandleCollision(Wall&)override;
    virtual void HandleCollision(Door&)override;
    virtual void HandleCollision(Key&)override;
    virtual void HandleCollision(Present&)override;
    virtual void HandleCollision(Cookie&)override;

private:
    int m_life = 3;
    int m_score = 0;
    int m_KeyCounter = 0;
    Direction m_direction = Stay;
    //std::unique_ptr <State> m_state;

    //Animation m_animation;
};