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
}

int Board::GetRow() const
{
	return m_row;
}

int Board::GetCol() const
{
	return m_col;
}

int Board::GetRowVec() const
{
	return m_StaticObjects.size();
}

int Board::GetColVec(const int row) const
{
	return m_StaticObjects[row].size();
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
	rec.setFillColor(sf::Color::Black);

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
		std::vector < std::unique_ptr< StaticObjects>> row_vector;
		for (int col = 0; col < m_col; col++)
		{
			char type = m_matrix.GetChar(row, col);
			if (type != 'a' && type != '&')
			{
				//row_vector.push_back(Getptr(type, row, col));
			}	
		}
		//m_StaticObjects.push_back(row_vector);
	}
}

sf::Sprite Board::GetStaticObject(const int row, const int col)
{
	return m_StaticObjects[row][col]->GetSprite();
}

std::unique_ptr<StaticObjects> Board::Getptr(const char type, const int row, const int col) const
{
	switch (type)
	{
	case 'D':
		return std::make_unique <Door>(row, col, m_row,m_col);

	case '%':
		return std::make_unique<Key>(row, col, m_row, m_col);

	case '$':
		return std::make_unique<Present>(row, col, m_row, m_col);

	case '*':
		return std::make_unique<Cookie>(row, col, m_row, m_col);
	}			
}


