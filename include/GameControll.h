#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Matrix.h"
#include "Board.h"
#include "Pacman.h"


const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height - 280;
const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width - 520;


class GameControll
{
public:
	GameControll();
	void run();
	void StartGame();
	void DrawGame();
	void handleClick(const sf::Vector2f&);
	void hendleMouseMoved(const sf::Vector2f);
	void DrawMenu();
	void DrawInstructions();
	void PlayVideo();


private:
	sf::RenderWindow m_window;
	Menu m_menu;
	Matrix m_matrix;
	Board m_board;
	Pacman m_pacman;

	sf::Clock m_game_clock;

};
