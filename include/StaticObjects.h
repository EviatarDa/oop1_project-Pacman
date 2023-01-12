#pragma once

#include <SFML/Graphics.hpp>

//abstruct class
class StaticObjects
{
public:
	StaticObjects(const int, const int, const int, const int);

	const  sf::Vector2f GetLocation() const;
	virtual sf::Sprite GetSprite() = 0;

private:
	sf::Vector2f m_location;
};
