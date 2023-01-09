#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>

class Key :public StaticObjects
{
public:
	Key();


private:
	const sf::Vector2f m_location;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};