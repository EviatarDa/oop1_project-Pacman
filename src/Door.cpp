#pragma once

#include "Door.h"

Door::Door(const int row, const int col, const int board_row, const int board_col, Object object )
	:StaticObjects(row, col, board_row, board_col, object)
{
}

void Door::HandleCollision(GameObject&)
{
}

void Door::HandleCollision(Pacman&)
{
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

void Door::HandleCollision(Present&)
{
}

void Door::HandleCollision(Cookie&)
{
}
