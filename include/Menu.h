#pragma once

#include <SFML/Graphics.hpp>

enum Button { TITLE ,PLAY, HELP, EXIT ,HELLO ,WANNA_PLAY ,INSTRUCTIONS }; 
const int SPRITES = 7;

class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetSprite(const Button) const;
	void ButtonPress(const Button);
	void ButtonRelease(const Button); 

private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	//menu pictures
	sf::Texture m_Title;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;
	sf::Texture m_Hello;
	sf::Texture m_WannaPlay;

	sf::Sprite m_buttons[SPRITES];

	//hidden picture
	sf::Texture m_Instructions;

	//functions
	void SetPosition();
};
