#include "AddTime.h"

AddTime::AddTime(const int row, const int col, const int board_row, const int board_col, Object object)
	:Present(row, col, board_row, board_col, object)
{
}

void AddTime::HandleCollision(Pacman& pacman)
{
	m_IsCollide = true;
	pacman.HandleCollision(*this);
}
