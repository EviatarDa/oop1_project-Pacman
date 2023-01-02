#pragma once

#include <SFML/Graphics.hpp>

const enum button { BACKGROUND ,PLAY, HELP, EXIT };
const int BUTTONS = 4;

class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetSprite(const button) const;

private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	sf::Texture m_BackGround;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;

	sf::Sprite m_buttons[BUTTONS];


	//functions
	void SetPosition();
};
