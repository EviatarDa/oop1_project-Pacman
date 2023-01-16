#pragma once

#include "Board.h"
#include <iostream>

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

int Board::GetRowVec() const
{
	return m_GameObjects.size();
}

int Board::GetColVec(const int row) const
{
	return m_GameObjects[row].size();
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
		std::vector < std::unique_ptr< GameObject>> row_vector;
		for (int col = 0; col < m_col; col++)
		{
			char type = m_matrix.GetChar(row, col);
			if (type != ' ')
			{
				row_vector.push_back(Getptr(type, row, col));
			}
		}
		m_GameObjects.push_back(std::move(row_vector));
	}
}

sf::Sprite Board::GetGameObject(const int row, const int col)
{
	return m_GameObjects[row][col]->GetSprite();
}

std::unique_ptr<GameObject> Board::Getptr(const char type, const int row, const int col) const
{
	switch (type)
	{
	case 'D':
		std::cout << " door at " << row << " " << col << std::endl;
		return std::make_unique <Door>(row, col, m_row, m_col, DOOR);

	case '%':
		std::cout << " key at " << row << " " << col << std::endl;
		return std::make_unique<Key>(row, col, m_row, m_col, KEY);

	case '$':
		std::cout << " present at " << row << " " << col << std::endl;
		return std::make_unique<Present>(row, col, m_row, m_col, PRESENT);

	case '*':
		std::cout << " cookie at " << row << " " << col << std::endl;
		return std::make_unique<Cookie>(row, col, m_row, m_col, COOKIE);

	case '#':
		std::cout << " wall at " << row << " " << col << std::endl;
		return std::make_unique<Wall>(row, col, m_row, m_col, WALL);

	//case 'a':
	//	std::cout << " pacman at " << row << " " << col << std::endl;
	//	return std::make_unique<Pacman>(row, col, m_row, m_col, PACMAN);

	//case '&':
	//	std::cout << " deamon at " << row << " " << col << std::endl;
	//	return std::make_unique<Deamon>(row, col, m_row, m_col, DEAMON);

	}			
}


