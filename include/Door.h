#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>


class Door :public StaticObjects
{
public:
	Door(const int, const int, const int, const int);
	sf::Sprite GetSprite();


private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};