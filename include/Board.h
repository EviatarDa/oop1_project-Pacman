#pragma once

#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include "GameObject.h"
#include "Key.h"
#include "SuperPresent.h"
#include "Freeze.h"
#include "AddLife.h"
#include "AddTime.h"
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
    int GetCookies() const;
    int GetEattenCookies() const;
    bool ReadNewLevel();
    void ResetMatrix();
    void UpdateDirection();
    const sf::RectangleShape CreateRectangle(const int, const int) const;
    sf::RectangleShape GetRectangle(const int, const int) const;
    void InitVector();
    sf::Sprite GetGameObjectMoving(const int);
    sf::Sprite GetGameObjectStatic(const int);
    int GetStaticSize()const;
    int GetMoveSize()const;
    void MoveObjects(sf::Time);
    void HandleCollisions(GameObject&);
    int ReturnPacmanLife() const;
    int ReturnPacmanScore() const;
    int ReturnPacmanKeys() const;
    void UpdateMoving(int&);
    void InitLevel();
    void SetPacmanData(int, int);


private:
    //members:
    std::vector<std::vector<sf::RectangleShape>> m_RectangleMatrix; //the board
    std::vector < std::unique_ptr< MovingObject>>  m_MovingObject;
    std::vector < std::unique_ptr< StaticObjects>>  m_StaticObject;

    Matrix m_matrix;
    int m_row;
    int m_col;
    int m_PacmanIndex;
    int m_Cookies = 0;
    

    //function 
    std::unique_ptr <StaticObjects> Getptrstatic(const char,const int, const int);
    std::unique_ptr <MovingObject> Getptrmove(const char,const int, const int) const;
    void CreateReactangles();   
    void ClearReactangles();  
    void initData();
};