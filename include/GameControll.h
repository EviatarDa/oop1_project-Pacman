#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Matrix.h"
#include "Board.h"


const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height - 300;
const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width - 500;


class GameControll
{
public:
	GameControll();
	void run();
	void handleClick(const sf::Vector2f&);
	void hendleMouseMoved(const sf::Vector2f);
	void DrawMenu();
	void DrawInstructions();


private:
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
	Matrix m_matrix;

};
