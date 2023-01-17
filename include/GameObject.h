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

protected:
	sf::Sprite m_sprite;

private:

	sf::Vector2f m_location;
};