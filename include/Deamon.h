#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Resources.h"


class Deamon : public MovingObject
{
public:
	Deamon(const int, const int, const int, const int, Object, Object);
	void UpdateDirection(sf::Keyboard::Key,sf::Vector2f);
	void Move(sf::Time);
	Direction PursuePacman(sf::Vector2f);

private:
	Direction m_direction = Stay;
	sf::Clock m_clock;
	sf::Time m_time;
	float m_Speed;
	int m_Type;

};
