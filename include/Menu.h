#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"


class Menu
{
public:
	Menu(int, int);
	sf::Sprite GetButton(const Button) const;
	sf::Sprite GetTitle(const Title) const;
	sf::Sprite GetInstructions(const Instructions) const;
	void PlaySound(const Sound);

	void ButtonPress(const Button);
	void ButtonRelease(const Button); 
	void UpdateVisible(const Title, int&, const int, const int);
	void MoveObject(const Title, const int, const int);
	void ResetLocation();
	void Mirror(const Title);
	void DisplayRules();
	void DropTheMic();
	void ResetRules();


private:

	//members
	const int m_WINDOW_HEIGHT;
	const int m_WINDOW_WIDTH;

	//arrays
	sf::Sprite m_Buttons[BUTTONS];
	sf::Sprite m_TitleObjects[TITLE_OBJECTS];
	sf::Sprite m_Instructions_Page[INSTRUCTIONS];
	sf::Sound m_Sound[SOUNDS];

	//functions
	void SetPosition();

};
