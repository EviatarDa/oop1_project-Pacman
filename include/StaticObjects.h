#pragma once

#include <SFML/Graphics.hpp>

//abstruct class
class StaticObjects
{
public:
	const  sf::Vector2f GetLocation() { return m_location; }
	 
private:
	const sf::Vector2f m_location;
};




