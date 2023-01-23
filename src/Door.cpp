#pragma once

#include "Door.h"

Door::Door(const int row, const int col, const int board_row, const int board_col, Object object )
	:StaticObjects(row, col, board_row, board_col, object)
{
}

void Door::HandleCollision(GameObject&)
{

}

void Door::HandleCollision(Pacman& pacman)
{
	pacman.HandleCollision(*this);
}

void Door::HandleCollision(Deamon& deamon)
{
	deamon.HandleCollision(*this);
}

void Door::HandleCollision(Wall&)
{
}

void Door::HandleCollision(Door&)
{
}

void Door::HandleCollision(Key&)
{
}

void Door::HandleCollision(SuperPresent&)
{
}

void Door::HandleCollision(AddTime&)
{
}

void Door::HandleCollision(Freeze&)
{
}

void Door::HandleCollision(AddLife&)
{
}


void Door::HandleCollision(Cookie&)
{
}

void Door::SetCollide()
{
	m_IsCollide = true;
}
