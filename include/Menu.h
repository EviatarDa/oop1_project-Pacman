#pragma once

#include <SFML/Graphics.hpp>

enum Button { VIDEO_PLAY, PLAY, HELP, EXIT };

enum Title { TITLE, HELLO, WANNA_PLAY, LETS_GO, PACMAN, DEMONS };

enum Instructions { INSTRUCTION };

const int BUTTONS = 4;
const int TITLE_OBJECTS = 6;
const int INSTRUCTIONS = 1;

class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetButton(const Button) const;
	sf::Sprite GetTitle(const Title) const;
	sf::Sprite GetInstructions(const Instructions) const;

	void ButtonPress(const Button);
	void ButtonRelease(const Button); 
	void UpdateVisible(const Title, int&, int);
	void UpdateLocation(const Title, int);
	void ResetLocation();
	void Mirror(const Title);


private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	//menu pictures:

	//buttons:
	sf::Texture m_VideoPlay;
	sf::Texture m_Play;
	sf::Texture m_Help;
	sf::Texture m_Exit;

	//Title:
	sf::Texture m_Title;
	sf::Texture m_Hello;
	sf::Texture m_WannaPlay;
	sf::Texture m_LetsGo;
	sf::Texture m_Pacman;
	sf::Texture m_Demons; 

	//Instruction:
	sf::Texture m_Instructions;
	//TOADD: exit button

	//arrays
	sf::Sprite m_buttons[BUTTONS];
	sf::Sprite m_TitleObjects[TITLE_OBJECTS];
	sf::Sprite m_Instructions_Page[INSTRUCTIONS];

	//functions
	void SetPosition();

};
