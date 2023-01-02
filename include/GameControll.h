#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"


const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height - 300;
const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width - 500;


class GameControll
{
public:
	GameControll();
	void run();
	void handleClick(const sf::Vector2f&);
	void DrawMenu();


private:
	sf::RenderWindow m_window;
	Menu m_menu;
	//Board m_board;
	//Matrix m_matrix;

};
