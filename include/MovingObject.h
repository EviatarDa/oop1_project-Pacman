#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject :public GameObject
{
public:
	MovingObject(const int, const int, const int, const int, Object);
	sf::Vector2f DirectionToVector(Direction);
	virtual void UpdateDirection(sf::Keyboard::Key, sf::Vector2f) = 0;
	virtual void UpdateDeamonsDirection(sf::Vector2f) = 0;
	virtual void Move(sf::Time) = 0;


private:
};
