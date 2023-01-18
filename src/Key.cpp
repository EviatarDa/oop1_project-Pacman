#pragma once

#include "Key.h"

Key::Key(const int row, const int col, const int board_row, const int board_col, Object object)
	:StaticObjects(row, col, board_row, board_col, object)
{
}

void Key::HandleCollision(GameObject&)
{
}

void Key::HandleCollision(Pacman&)
{
}

void Key::HandleCollision(Deamon&)
{
}

void Key::HandleCollision(Wall&)
{
}

void Key::HandleCollision(Door&)
{
}

void Key::HandleCollision(Key&)
{
}

void Key::HandleCollision(Present&)
{
}

void Key::HandleCollision(Cookie&)
{
}
