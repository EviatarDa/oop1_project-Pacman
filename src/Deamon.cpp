#pragma once

#include "Deamon.h"

Deamon::Deamon(const int row, const int col, const int board_row, const int board_col, Object object, Object type)
	: MovingObject(row, col, board_row, board_col, object), m_Type(type), m_Speed(200)
{
}

void Deamon::UpdateDirection(sf::Vector2f PacLocation)
{
	switch (m_Type)
	{
	case DEAMON_AZURE:
		m_direction = PursueTarget(PacLocation);
		m_Speed = 100.f;
		break;

	case DEAMON_ORANGE:
		m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (4 * 50.f), PacLocation.y));
		m_Speed = 50.f;
		break;

	case DEAMON_PINK:
		m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (2 * 50.f), PacLocation.y));
		m_Speed = 150.f;
		break;

	case DEAMON_RED:
		m_direction = PursueTarget(sf::Vector2f(PacLocation.x + (2 * 50.f), PacLocation.y + (2 * 50.f)));
		m_Speed = 100.f;
		break;

	default:
		break;
	}
}

void Deamon::Move(sf::Time delta)
{
	m_last_locatiom = m_location;
	m_sprite.move(DirectionToVector(m_direction) * delta.asSeconds()* m_Speed);
}

Direction Deamon::PursueTarget(sf::Vector2f Target)
{
	float my_Pixlcol = this->GetSprite().getPosition().x;
	float my_Pixlrow = this->GetSprite().getPosition().y;

	if ((Target.x - 20.f < my_Pixlcol && my_Pixlcol < Target.x + 20.f) &&
		(Target.y - 20.f < my_Pixlrow && my_Pixlrow < Target.y + 20.f))
	{
		return Stay;
	}


	if (Target.y - 5.f > my_Pixlrow)
	{
		return Down;
	}
	else if (Target.x - 5.f < my_Pixlcol)
	{
		return Left;
	}
	else if (Target.x - 20.f > my_Pixlcol)
	{
		return Right;
	}
	else if (Target.y - 5.f < my_Pixlrow)
	{
		return Up;
	}
}

void Deamon::HandleCollision(GameObject& game_object)
{
	game_object.HandleCollision(*this);
}

void Deamon::HandleCollision(Pacman&)
{
}

void Deamon::HandleCollision(Deamon&)
{
}

void Deamon::HandleCollision(Wall& wall)
{
	m_location = m_last_locatiom;
	m_sprite.move(OppositeVector(m_direction) * 0.1f *  150.f); ////fix delta
}

void Deamon::HandleCollision(Door&)
{
	m_location = m_last_locatiom;
	m_sprite.move(OppositeVector(m_direction) * 0.1f * 150.f); ////fix delta
}

void Deamon::HandleCollision(Key&)
{
}

void Deamon::HandleCollision(Present&)
{
}

void Deamon::HandleCollision(Cookie&)
{
}
