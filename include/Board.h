#pragma once

#include <SFML/Graphics.hpp>

class Board
{
public:
    Board(const int, const int);
    const sf::RectangleShape CreateRectangle(const int, const int) const;
    sf::RectangleShape GetRectangle(const int, const int) const;


private:
    std::vector<std::vector<sf::RectangleShape>> m_RectangleMatrix; //the board
    int m_row;
    int m_col;
};