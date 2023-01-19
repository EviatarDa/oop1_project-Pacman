#pragma once

#include "Cookie.h"

Cookie::Cookie(const int row, const int col, const int board_row, const int board_col, Object object)
	:StaticObjects(row, col, board_row, board_col, object)
{

}

void Cookie::HandleCollision(GameObject&)
{
}

void Cookie::HandleCollision(Pacman& pacman)
{
	m_IsCollide = true;
	pacman.HandleCollision(*this);
}

void Cookie::HandleCollision(Deamon&)
{
}

void Cookie::HandleCollision(Wall&)
{
}

void Cookie::HandleCollision(Door&)
{
}

void Cookie::HandleCollision(Key&)
{
}

void Cookie::HandleCollision(Present&)
{
}

void Cookie::HandleCollision(Cookie&)
{
}
