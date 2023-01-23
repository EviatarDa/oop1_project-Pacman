#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Resources.h"
#include "SuperPacmanState.h"
#include "NormalPacman.h"


const float PACMAN_SPEED = 150;

class Pacman : public MovingObject
{
public:
    Pacman(const int , const int , const int , const int , Object );
    void UpdateDirection(sf::Vector2f);
    void Move(sf::Time);
    void UpgradeToSuper();
    void DowngradeToNormal();
    int GetKeyCounter();
    void DecKeys();
    void DecLife();
    void SetLastLocation();////////////new;
    void SetLife(); /////////////////new shir
    int GetLife();////////////new shir
    int GetScore();
    int GetKeys(); 
    int GetEatten();
    void SetCookies();
    void UpdateState(bool, int&)override;

    void SetLife(int);
    void SetScore(int);

    virtual void HandleCollision(GameObject&)override;
    virtual void HandleCollision(Pacman&)override;
    virtual void HandleCollision(Deamon&)override;
    virtual void HandleCollision(Wall&)override;
    virtual void HandleCollision(Door&)override;
    virtual void HandleCollision(Key&)override;
    virtual void HandleCollision(SuperPresent&)override;
    virtual void HandleCollision(AddTime&)override;
    virtual void HandleCollision(Freeze&)override;
    virtual void HandleCollision(AddLife&)override;
    virtual void HandleCollision(Cookie&)override;

private:
    int m_life = 3;
    int m_score = 0;
    int m_KeyCounter = 0;
    int m_EattenCookies = 0;
    int m_time_collected = 0;

    sf::Time m_SuperTime;
    sf::Time m_FreezeTime;
    sf::Clock m_PaClock;
    Direction m_direction = Stay;
    std::unique_ptr <PacmanState> m_state;
    sf::Sound m_Sounds[SOUNDS];

    //Animation m_animation;
};