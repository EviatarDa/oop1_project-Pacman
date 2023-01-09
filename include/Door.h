#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>


class Door :public StaticObjects
{
public:
	Door();


private:
	const sf::Vector2f m_location;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};