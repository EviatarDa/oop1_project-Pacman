#pragma once

#include "Deamon.h"

Deamon::Deamon(const int row, const int col, const int board_row, const int board_col, Object object, Object type)
	: MovingObject(row, col, board_row, board_col, object), m_Type(type), m_Speed(200)
{
}

void Deamon::UpdateDirection(sf::Keyboard::Key key, sf::Vector2f PacLocation)
{	
	switch (m_Type)
	{
	case DEAMON_AZURE:
		m_Speed = 200.f;
		m_direction = PursuePacman(PacLocation);
		break;

	case DEAMON_ORANGE:
		m_Speed = 200.f;
		m_direction = PursuePacman(PacLocation);
		break;

	case DEAMON_PINK:
		m_direction = PursuePacman(PacLocation);
		m_Speed = 200.f;
		break;

	case DEAMON_RED:
		m_direction = PursuePacman(PacLocation);
		m_Speed = 200.f;
		break;

	default:
		break;
	}
}

void Deamon::Move(sf::Time delta  )
{
	this->GetSprite().move(DirectionToVector(m_direction) * delta.asSeconds()* m_Speed);
}

Direction Deamon::PursuePacman(sf::Vector2f PacLocation)
{
	float Xdistance = this->GetSprite().getPosition().x - PacLocation.x;
	float Ydistance = this->GetSprite().getPosition().y - PacLocation.y;
	if (Xdistance > 0)
	{
		return Left;
	}
	else if (Xdistance < 0)
	{
		return Right;
	}
	else if (Ydistance > 0)
	{
		return Down;
	}
	else if (Ydistance < 0)
	{
		return Up;
	}
	else
	{
		return Down;
	}
}
