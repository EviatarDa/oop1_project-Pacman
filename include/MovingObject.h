#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject :public GameObject
{
public:
	MovingObject(const int, const int, const int, const int, Object);
	sf::Vector2f DirectionToVector(Direction);
	virtual void UpdateDirection(sf::Keyboard::Key, sf::Vector2f) = 0;
	virtual void Move(sf::Time) = 0;
	sf::Clock m_game_clock;


private:
};
