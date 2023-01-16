#pragma once

#include "Key.h"

Key::Key(const int row, const int col, const int board_row, const int board_col, Object object)
	:StaticObjects(row, col, board_row, board_col, object)
{
}
