#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
//#include "StaticObjects.h"
//#include "MovingObject.h"


class GameObject
{
public:
	GameObject(const int, const int, const int, const int, Object);
	sf::Sprite& GetSprite();
	virtual void UpdateDirection(sf::Keyboard::Key, sf::Vector2f) = 0;
	virtual void Move(sf::Time) = 0;
	

private:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};