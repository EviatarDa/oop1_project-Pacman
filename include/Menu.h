#pragma once

#include <SFML/Graphics.hpp>

enum Button {  PLAY, HELP, EXIT, VIDEO_PLAY, BACK };

enum Title {  TITLE, HELLO, WANNA_PLAY, LETS_GO, PACMAN, DEMONS };

enum Instructions { SHIR, EVIATAR1, EVIATAR2, SHIR_DROP, EVIATAR_DROP, OH_NO, GAME_RULES };

const int BUTTONS = 5;
const int TITLE_OBJECTS = 6;
const int INSTRUCTIONS = 7;

class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetButton(const Button) const;
	sf::Sprite GetTitle(const Title) const;
	sf::Sprite GetInstructions(const Instructions) const;

	void ButtonPress(const Button);
	void ButtonRelease(const Button); 
	void UpdateVisible(const Title, int&, const int, const int);
	void MoveObject(const Title, const int, const int);
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
	sf::Texture m_Back;


	//Title:
	sf::Texture m_Title;
	sf::Texture m_Hello;
	sf::Texture m_WannaPlay;
	sf::Texture m_LetsGo;
	sf::Texture m_Pacman;
	sf::Texture m_Demons; 

	//Instruction:
	sf::Texture m_shir;
	sf::Texture m_eviatar1;
	sf::Texture m_eviatar2;
	sf::Texture m_EviatarDrop;
	sf::Texture m_ShirDrop;
	sf::Texture m_OhNo;
	sf::Texture m_GameRules;

	//arrays
	sf::Sprite m_buttons[BUTTONS];
	sf::Sprite m_TitleObjects[TITLE_OBJECTS];
	sf::Sprite m_Instructions_Page[INSTRUCTIONS];

	//functions
	void SetPosition();

};
