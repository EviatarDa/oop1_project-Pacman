#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>

class Cookie :public StaticObjects
{
public:
	Cookie(const int, const int, const int, const int);
	sf::Sprite GetSprite();


private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};