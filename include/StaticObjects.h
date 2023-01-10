#pragma once

#include <SFML/Graphics.hpp>

//abstruct class
class StaticObjects
{
public:

	const  sf::Vector2f GetLocation() const { return m_location; }
	void SetLocation(const int, const int); // TODO 
	 
private:
	const sf::Vector2f m_location;
};
