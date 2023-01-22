#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Resources.h"
#include "Board.h"
#include "Pacman.h"
//#include "Deamon.h"
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
	void PlayMusic();
	void DrawToolBar();
	void UpdateData();


private:
//	sf::SoundBuffer m_song;
	sf::RenderWindow m_window;
	Resources& m_resource = Resources::instance();
	Menu m_menu;
	Board m_board;
	ToolBar m_toolbar;
	sf::Sound m_Sound;
	sf::Clock m_game_clock;
	int m_level = 1;




};
