#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
//#include "StaticObjects.h"
//#include "MovingObject.h"


class GameObject
{
public:
	GameObject(const int, const int, const int, const int, Object);
	sf::Sprite GetSprite();
	

private:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};