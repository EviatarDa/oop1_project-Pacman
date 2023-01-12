#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>

class Wall :public StaticObjects
{
public:
	Wall(const int, const int, const int, const int);
	sf::Sprite GetSprite();


private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};