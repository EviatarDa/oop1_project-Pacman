#pragma once

#include <SFML/Graphics.hpp>

enum Button { TITLE, VIDEO_PLAY, PLAY, HELP, EXIT ,HELLO ,WANNA_PLAY, PACMAN, DEMONS,INSTRUCTIONS };
const int SPRITES = 10;

class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetSprite(const Button) const;
	void ButtonPress(const Button);
	void ButtonRelease(const Button); 
	void UpdateVisible(const Button, int&);
	void Mirror(const Button);

private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	//menu pictures
	sf::Texture m_Title;
	sf::Texture m_VideoPlay;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;
	sf::Texture m_Hello;
	sf::Texture m_WannaPlay;
	sf::Texture m_Instructions; //hidden picture
	sf::Texture m_Pacman; //new
	sf::Texture m_Demons; //new

	sf::Sprite m_buttons[SPRITES];

	


	//functions
	void SetPosition();
};
