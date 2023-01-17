#pragma once

#include "Deamon.h"

Deamon::Deamon(const int row, const int col, const int board_row, const int board_col, Object object, Object type)
	: MovingObject(row, col, board_row, board_col, object), m_Type(type), m_Speed(200)
{
}

void Deamon::UpdateDirection(sf::Keyboard::Key key, sf::Vector2f PacLocation)
{

}

void Deamon::UpdateDeamonsDirection(sf::Vector2f PacLocation)
{
	{
		switch (m_Type)
		{
		case DEAMON_AZURE:
			m_direction = PursueTarget(PacLocation);
			m_Speed = 200.f;
			break;

		case DEAMON_ORANGE:
			m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (4*50.f),PacLocation.y));
			m_Speed = 200.f;
			break;

		case DEAMON_PINK:
			m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (2 * 50.f), PacLocation.y));
			m_Speed = 200.f;
			break;

		case DEAMON_RED:
			m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (2 * 50.f), PacLocation.y + (2 * 50.f)));
			m_Speed = 200.f;
			break;

		default:
			break;
		}
	}
}

void Deamon::Move(sf::Time delta  )
{
	this->GetSprite().move(DirectionToVector(m_direction) * delta.asSeconds()* m_Speed);
}

Direction Deamon::PursueTarget(sf::Vector2f Target)
{
	float my_Pixlcol = this->GetSprite().getPosition().x;
	float my_Pixlrow = this->GetSprite().getPosition().y;

	float target_Pixlcol = Target.x;
	float target_Pixlrow = Target.y;

	float my_col = (this->GetSprite().getPosition().x - (1400 - 20 * 50.f) / 2) / 50;
	float my_row = (this->GetSprite().getPosition().y - (800 - 16 * 50.f) / 2) / 50;

	float target_col = (Target.x - (1400 - 20 * 50.f) / 2) / 50;
	float target_row = (Target.y - (800 - 16 * 50.f) / 2) / 50;

	float Xdistance = my_col - target_col;
	float Ydistance = my_row - target_row;

	if ((target_Pixlcol - 5.f < my_Pixlcol && my_Pixlcol < target_Pixlcol+5.f) &&
		(target_Pixlrow - 5.f < my_Pixlrow && my_Pixlrow < target_Pixlrow + 5.f))
	{
		return Stay;
	}

	if (Xdistance > 0) 
	{
		return Left;
	}
	else if (Ydistance < 0)
	{
		return Down;
	}
	else if (Xdistance < 0)
	{
		return Right;
	}
	else //if (Ydistance > 0)
	{
		return Up;
	}
}
