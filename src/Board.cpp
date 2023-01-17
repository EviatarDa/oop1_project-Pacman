#pragma once

#include "Board.h"

Board::Board()
	:m_matrix(), m_row(m_matrix.GetRow()), m_col(m_matrix.GetCol())
{
	for (int row = 0; row < m_row; ++row)
	{
		std::vector < sf::RectangleShape > vector_row;
		for (int col = 0; col < m_col; ++col)
		{
			vector_row.push_back(CreateRectangle(row, col)); // create the corrent row
		}
		m_RectangleMatrix.push_back(vector_row); // push the vector to the vector
	}
	InitVector();
}

int Board::GetRow() const
{
	return m_row;
}

int Board::GetCol() const
{
	return m_col;
}

int Board::GetRowVecMove() const
{
	return m_MovingObject.size();
}

int Board::GetRowVecStat() const
{
	return m_StaticObject.size();

}

int Board::GetColVecMove(const int row) const
{
	return m_MovingObject[row].size();
}

int Board::GetColVecStat(const int row) const
{
	return m_StaticObject[row].size();

}

void Board::UpdateDirection(sf::Keyboard::Key key)
{
	for (int row = 0; row < this->GetRowVecMove(); ++row)
	{
		for (int col = 0; col < this->GetColVecMove(row); ++col)
		{
			m_MovingObject[row][col]->UpdateDirection(key, GetGameObjectMoving(m_P2Pacman.x,m_P2Pacman.y).getPosition());
		}
	}
}


const sf::RectangleShape Board::CreateRectangle(const int row, const int col) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2f(50.f, 50.f));
	rec.setPosition((float)((1400 - m_col * 50.f) / 2 + (col * 50.f)),
					(float)((800 - m_row * 50.f) / 2 + (row * 50.f)));

	//Style
	rec.setOutlineColor(sf::Color::Color(102, 102, 102));
	rec.setOutlineThickness(1.f);
	rec.setFillColor(sf::Color::White);

	return rec;
}

sf::RectangleShape Board::GetRectangle(const int row, const int col) const
{
	return m_RectangleMatrix[row][col];

}

void Board::InitVector()
{
	for (int row = 0; row < m_row; row++)
	{
		std::vector < std::unique_ptr< MovingObject>> row_vector_move;
		std::vector < std::unique_ptr< StaticObjects>> row_vector_static;
		for (int col = 0; col < m_col; col++)
		{
			char type = m_matrix.GetChar(row, col);
			if (type == 'a' || type == '&')
			{
				row_vector_move.push_back(Getptrmove(type, row, col));
				if (type == 'a')
				{
					int Prow = GetRowVecMove();
					int Pcol = row_vector_move.size() - 1;
					m_P2Pacman = { Prow,Pcol };
				}
			}
			else if (type != ' ')
			{
				row_vector_static.push_back(Getptrstatic(type, row, col));
			}
	
		}
		m_MovingObject.push_back(std::move( row_vector_move));
		m_StaticObject.push_back(std::move(row_vector_static));
	}
}

sf::Sprite Board::GetGameObjectMoving(const int row, const int col)
{
	return m_MovingObject[row][col]->GetSprite();
}

sf::Sprite Board::GetGameObjectStatic(const int row, const int col)
{
	return m_StaticObject[row][col]->GetSprite();
}

void Board::MoveObjects(sf::Time delta)
{
	for (int row = 0; row < this->GetRowVecMove(); row++)
	{
		for (int col = 0; col < this->GetColVecMove(row); col++)
		{
			m_MovingObject[row][col]->Move(delta);
		}
	}
}

std::unique_ptr<StaticObjects> Board::Getptrstatic(const char type, const int row, const int col) const
{
	switch (type)
	{
	case 'D':
		return std::make_unique <Door>(row, col, m_row, m_col, DOOR);

	case '%':
		return std::make_unique<Key>(row, col, m_row, m_col, KEY);

	case '$':
		return std::make_unique<Present>(row, col, m_row, m_col, PRESENT);

	case '*':
		return std::make_unique<Cookie>(row, col, m_row, m_col, COOKIE);

	case '#':
		return std::make_unique<Wall>(row, col, m_row, m_col, WALL);

	}
}

std::unique_ptr<MovingObject> Board::Getptrmove(const char type, const int row, const int col) const
{
	switch (type)
	{

	case 'a':
		return std::make_unique<Pacman>(row, col, m_row, m_col, PACMAN);

	case '&':
	{
		static int add = 0;
		add++;
		add %= 4;
		return std::make_unique<Deamon>(row, col, m_row, m_col, (Object)(DEAMON_ORANGE + add), (Object)(DEAMON_ORANGE + add));///todo fix
	}
	}


}




//int Board::AddMod4()
//{
//	static int add = 0;
//	add++;
//	return add % 4;
// 
// 		switch (add)
		//{
		//case 0:
		//	break;

		//case 1:
		//	break;

		//case 2:
		//	break;

		//case 3:
		//	break;

//}


