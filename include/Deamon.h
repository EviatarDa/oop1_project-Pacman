#pragma once

#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Resources.h"


class Deamon : public MovingObject
{
public:
	Deamon(const int, const int, const int, const int, Object, Object);
	void UpdateDirection(sf::Vector2f);
	void Move(sf::Time);
	Direction PursueTarget(sf::Vector2f);
	virtual void HandleCollision(GameObject&)override;
	virtual void HandleCollision(Pacman&)override;
	virtual void HandleCollision(Deamon&)override;
	virtual void HandleCollision(Wall&)override;
	virtual void HandleCollision(Door&)override;
	virtual void HandleCollision(Key&)override;
	virtual void HandleCollision(Present&)override;
	virtual void HandleCollision(Cookie&)override;

private:
	Direction m_direction = Stay;
	sf::Clock m_clock;
	sf::Time m_time;
	float m_Speed;
	int m_Type;

};
