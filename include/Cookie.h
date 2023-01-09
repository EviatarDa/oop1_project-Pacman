#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>

class Cookie :public StaticObjects
{
public:
	Cookie();


private:
	const sf::Vector2f m_location;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};