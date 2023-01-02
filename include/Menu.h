#pragma once

#include <SFML/Graphics.hpp>

const enum button { PLAY, HELP, EXIT };
const int BUTTONS = 3;

class Menu
{
public:
	Menu();
	sf::Sprite GetSprite(const button) const;

private:

	//members
	//sf::Texture m_BackGroung;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;

	sf::Sprite m_buttons[BUTTONS];


	//functions
	void SetPosition();
};
