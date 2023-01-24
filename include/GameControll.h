#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Resources.h"
#include "Board.h"
#include "Pacman.h"
#include "StaticObjects.h"
#include "ToolBar.h"


const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 1400;


class GameControll
{
public:
	GameControll();
	void DrawMenu();
	void run();
	void StartGame();
	void DrawGame();
	void handleClick(const sf::Vector2f&);
	void handleNextClick(const sf::Vector2f&, bool&);
	void handleMouseMoved(const sf::Vector2f, const Button, const Button);
	void InstructionsLoop();
	void DrawInstructions();
	void BrighteningSprite(Title, int&, int, int);
	void PlayVideo();
	void DrawToolBar();
	void UpdateData();


private:
	sf::RenderWindow m_window;
	Resources& m_resource = Resources::instance();
	Menu m_menu;
	Board m_board;
	ToolBar m_toolbar;
	sf::Sound m_Sound[2];
	sf::Clock m_GameClock;
	sf::Clock m_MoveClock;
	sf::Time m_LevelTime;
	int m_level = 1;
	int m_AddedTime = 0;

};
