#pragma once

#include "Board.h"

Board::Board(const int row, const int col)
	:m_row(row), m_col(col)
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


const sf::RectangleShape Board::CreateRectangle(const int row, const int col) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2(50.f, 50.f));
	rec.setPosition((float)((1000 - m_row * 50.f) / 2 + (row * 50.f)),
		(float)((900 - m_col * 50.f) / 2 + (col * 50.f)));

	//Style
	rec.setOutlineColor(sf::Color::Color(102, 102, 102));
	rec.setOutlineThickness(1.f);
	rec.setFillColor(sf::Color::Transparent);

	return rec;
}
