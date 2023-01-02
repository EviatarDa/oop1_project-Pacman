#pragma once

#include <SFML/Graphics.hpp>

const enum button { BACKGROUND ,PLAY, HELP, EXIT };
const int BUTTONS = 4;

class Menu
{
public:
	Menu();
	sf::Sprite GetSprite(const button) const;

private:

	//members
	//sf::Texture m_BackGround;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;
	sf::Texture m_BackGroung;

	sf::Sprite m_buttons[BUTTONS];


	//functions
	void SetPosition();
};
