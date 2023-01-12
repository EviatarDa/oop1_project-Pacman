#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
//#include "Matrix.h"
#include "Board.h"
#include "Pacman.h"
//#include "Deamon.h"
#include "StaticObjects.h"


const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;


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
	void PlayMusic();//


private:
	sf::RenderWindow m_window;

	sf::Sound m_Sound;
	sf::SoundBuffer m_song;

	Menu m_menu;
	Board m_board;
	Pacman m_pacman;

	sf::Clock m_game_clock;

};
