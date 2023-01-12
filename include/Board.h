#pragma once

#include <SFML/Graphics.hpp>
//#include <memory.h>
#include "Matrix.h"
#include "StaticObjects.h"
#include "Key.h"
#include "Present.h"
#include "Door.h"
#include "Cookie.h"
#include "Wall.h"

class Board
{
public:
    Board();
    int GetRow() const;
    int GetCol() const;
    int GetRowVec()const;
    int GetColVec(const int) const;

    const sf::RectangleShape CreateRectangle(const int, const int) const;
    sf::RectangleShape GetRectangle(const int, const int) const;
    void InitVector();
    sf::Sprite GetStaticObject(const int, const int);


private:
    std::vector<std::vector<sf::RectangleShape>> m_RectangleMatrix; //the board
    std::vector < std::vector < std::unique_ptr< StaticObjects>> > m_StaticObjects;
    Matrix m_matrix;
    int m_row;
    int m_col;

    //function ;
    std::unique_ptr <StaticObjects> Getptr(const char,const int, const int) const;
};