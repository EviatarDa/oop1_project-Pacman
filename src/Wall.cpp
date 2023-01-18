#pragma once

#include "Wall.h"

Wall::Wall(const int row, const int col, const int board_row, const int board_col, Object object)
	:StaticObjects(row, col, board_row, board_col, object)
{
}

void Wall::HandleCollision(GameObject&)
{

}

void Wall::HandleCollision(Pacman& pacman)
{
	pacman.HandleCollision(*this);
}

void Wall::HandleCollision(Deamon& deamon)
{
	deamon.HandleCollision(*this);
}

void Wall::HandleCollision(Wall&)
{

}

void Wall::HandleCollision(Door&)
{

}

void Wall::HandleCollision(Key&)
{
}

void Wall::HandleCollision(Present&)
{
}

void Wall::HandleCollision(Cookie&)
{
}

