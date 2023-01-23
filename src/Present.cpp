#pragma once

#include "Present.h"

Present::Present(const int row, const int col, const int board_row, const int board_col, Object object)
	:StaticObjects(row, col, board_row, board_col, object)
{
}

void Present::HandleCollision(GameObject&)
{
}

void Present::HandleCollision(Pacman&)
{
}

void Present::HandleCollision(Deamon&)
{
}

void Present::HandleCollision(Wall&)
{
}

void Present::HandleCollision(Door&)
{
}

void Present::HandleCollision(Key&)
{
}

void Present::HandleCollision(SuperPresent&)
{
}

void Present::HandleCollision(AddTime&)
{
}

void Present::HandleCollision(Freeze&)
{
}

void Present::HandleCollision(AddLife&)
{
}

void Present::HandleCollision(Cookie&)
{
}
