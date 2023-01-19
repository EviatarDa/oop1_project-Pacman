#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject :public GameObject
{
public:
	MovingObject(const int, const int, const int, const int, Object);
	sf::Vector2f DirectionToVector(Direction);
	sf::Vector2f OppositeVector(Direction);
	virtual void UpdateDirection(sf::Vector2f) = 0;
	virtual void Move(sf::Time) = 0;



private:
	//sf::Vector2f m_last_location;// = m_location;
};
