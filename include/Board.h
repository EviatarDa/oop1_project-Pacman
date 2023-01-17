#pragma once

#include <SFML/Graphics.hpp>
//#include <memory.h>
#include "Matrix.h"
#include "GameObject.h"
#include "Key.h"
#include "Present.h"
#include "Door.h"
#include "Cookie.h"
#include "Wall.h"
#include "Pacman.h"
#include "Deamon.h"

class Board
{
public:
    Board();
    int GetRow() const;
    int GetCol() const;
    int GetRowVecMove()const;
    int GetRowVecStat()const;
    int GetColVecMove(const int) const;
    int GetColVecStat(const int) const;
    void UpdateDirection();
    const sf::RectangleShape CreateRectangle(const int, const int) const;
    sf::RectangleShape GetRectangle(const int, const int) const;
    void InitVector();
    sf::Sprite GetGameObjectMoving(const int, const int);
    sf::Sprite GetGameObjectStatic(const int, const int);
    void MoveObjects(sf::Time);


private:
    std::vector<std::vector<sf::RectangleShape>> m_RectangleMatrix; //the board
    std::vector < std::vector < std::unique_ptr< MovingObject>> > m_MovingObject;
    std::vector < std::vector < std::unique_ptr< StaticObjects>> > m_StaticObject;

    Matrix m_matrix;
    int m_row;
    int m_col;
    sf::Vector2i m_P2Pacman;

    //function ;
    std::unique_ptr <StaticObjects> Getptrstatic(const char,const int, const int) const;
    std::unique_ptr <MovingObject> Getptrmove(const char,const int, const int) const;
    //int AddMod4();
};