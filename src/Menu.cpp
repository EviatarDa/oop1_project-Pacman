#pragma once

#include "Menu.h"

Menu::Menu(int width, int height)
	:m_WINDOW_WIDTH(width), m_WINDOW_HEIGHT(height)
{
	//load from file
	m_Title.loadFromFile("title.png");
	m_VideoPlay.loadFromFile("VideoPlay.png");
	m_Play.loadFromFile("Play.png");
	m_Help.loadFromFile("Help.png");
	m_Exit.loadFromFile("Exit.png");
	m_Back.loadFromFile("Back.png");
	m_Hello.loadFromFile("Hello.png");
	m_WannaPlay.loadFromFile("WannaPlay.png");
	m_LetsGo.loadFromFile("LetsGo.png");
	m_Pacman.loadFromFile("Pacman-Title.png"); 
	m_Demons.loadFromFile("Deamons-Title.png");
	m_shir.loadFromFile("Shir.png");
	m_eviatar1.loadFromFile("Eviatar1.png");
	m_eviatar2.loadFromFile("Eviatar2.png");
	m_ShirDrop.loadFromFile("ShirDrop.png");
	m_EviatarDrop.loadFromFile("EviatarDrop.png");
	m_OhNo.loadFromFile("OhNo.png");
	m_GameRules.loadFromFile("GameRules.png");

	//make it looks good
	m_Title.setSmooth(true);
	m_Pacman.setSmooth(true);
	m_shir.setSmooth(true);
	m_eviatar1.setSmooth(true);
	m_eviatar2.setSmooth(true);
	m_ShirDrop.setSmooth(true);
	m_EviatarDrop.setSmooth(true);

	//define the array:
	m_buttons[VIDEO_PLAY].setTexture(m_VideoPlay);
	m_buttons[PLAY].setTexture(m_Play);
	m_buttons[HELP].setTexture(m_Help);
	m_buttons[EXIT].setTexture(m_Exit);
	m_buttons[BACK].setTexture(m_Back);

	m_TitleObjects[TITLE].setTexture(m_Title);
	m_TitleObjects[HELLO].setTexture(m_Hello);
	m_TitleObjects[WANNA_PLAY].setTexture(m_WannaPlay);
	m_TitleObjects[LETS_GO].setTexture(m_LetsGo);
	m_TitleObjects[PACMAN].setTexture(m_Pacman);
	m_TitleObjects[DEMONS].setTexture(m_Demons);

	m_Instructions_Page[SHIR].setTexture(m_shir);
	m_Instructions_Page[EVIATAR1].setTexture(m_eviatar1);
	m_Instructions_Page[EVIATAR2].setTexture(m_eviatar2);
	m_Instructions_Page[SHIR_DROP].setTexture(m_ShirDrop);
	m_Instructions_Page[EVIATAR_DROP].setTexture(m_EviatarDrop);
	m_Instructions_Page[OH_NO].setTexture(m_OhNo);
	m_Instructions_Page[GAME_RULES].setTexture(m_GameRules);

	//define the first visibility
	m_TitleObjects[HELLO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[WANNA_PLAY].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[LETS_GO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[PACMAN].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[DEMONS].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	//m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));
	SetPosition();
}

sf::Sprite Menu::GetButton(const Button object) const
{
	return m_buttons[object];
}

sf::Sprite Menu::GetTitle(const Title object) const
{
	return m_TitleObjects[object];
}

sf::Sprite Menu::GetInstructions(const Instructions object) const
{
	return m_Instructions_Page[object];
}

void Menu::ButtonPress(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

void Menu::ButtonRelease(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255));
}

void Menu::UpdateVisible(Title object, int& curr_brightness, const int add, const int brightness)
{
	curr_brightness += add;
	if ((curr_brightness > brightness && add > 0) || (curr_brightness < brightness && add < 0))
	{
		curr_brightness = brightness;
	}
	m_TitleObjects[object].setColor(sf::Color::Color(255, 255, 255, curr_brightness));
}

void Menu::MoveObject(const Title object, const int x, const int y)
{
	m_TitleObjects[object].move(x, y);

}

void Menu::ResetLocation()
{
	m_TitleObjects[PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.249, m_WINDOW_HEIGHT * 0.265));

	m_TitleObjects[DEMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.495, m_WINDOW_HEIGHT * 0.265));
}

void Menu::Mirror(const Title object)
{
	m_TitleObjects[object].scale(-1, 1);
}

void Menu::SetPosition()
{
	//resize:
	//Buttons:
	m_buttons[PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width));

	m_buttons[HELP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width));

	m_buttons[EXIT].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width));

	m_buttons[BACK].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.12 / m_buttons[BACK].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.12 / m_buttons[BACK].getTextureRect().width));

	m_buttons[VIDEO_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width));

	//Title:
	m_TitleObjects[TITLE].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width));

	m_TitleObjects[HELLO].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.075 / m_TitleObjects[HELLO].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.075 / m_TitleObjects[HELLO].getTextureRect().width));

	m_TitleObjects[WANNA_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.1 / m_TitleObjects[WANNA_PLAY].getTextureRect().width,
												  m_WINDOW_WIDTH * 0.1 / m_TitleObjects[WANNA_PLAY].getTextureRect().width));

	m_TitleObjects[LETS_GO].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.075 / m_TitleObjects[LETS_GO].getTextureRect().width,
										   	   m_WINDOW_WIDTH * 0.075 / m_TitleObjects[LETS_GO].getTextureRect().width));

	m_TitleObjects[PACMAN].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.053 / m_TitleObjects[PACMAN].getTextureRect().width,
											  m_WINDOW_WIDTH * 0.053 / m_TitleObjects[PACMAN].getTextureRect().width));

	m_TitleObjects[DEMONS].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.257 / m_TitleObjects[DEMONS].getTextureRect().width,
											  m_WINDOW_WIDTH * 0.257 / m_TitleObjects[DEMONS].getTextureRect().width));

	//Instructions:
	m_Instructions_Page[SHIR].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[SHIR].getTextureRect().width,
												 m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[SHIR].getTextureRect().width));

	m_Instructions_Page[EVIATAR1].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.15 / m_Instructions_Page[EVIATAR1].getTextureRect().width,
													 m_WINDOW_WIDTH * 0.15 / m_Instructions_Page[EVIATAR1].getTextureRect().width));

	m_Instructions_Page[EVIATAR2].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[EVIATAR2].getTextureRect().width,
												  	 m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[EVIATAR2].getTextureRect().width));

	m_Instructions_Page[SHIR_DROP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[SHIR_DROP].getTextureRect().width,
													  m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[SHIR_DROP].getTextureRect().width));

	m_Instructions_Page[EVIATAR_DROP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[EVIATAR_DROP].getTextureRect().width,
														 m_WINDOW_WIDTH * 0.2 / m_Instructions_Page[EVIATAR_DROP].getTextureRect().width));
	
	m_Instructions_Page[GAME_RULES].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.65 / m_Instructions_Page[GAME_RULES].getTextureRect().width,
													   m_WINDOW_WIDTH * 0.65 / m_Instructions_Page[GAME_RULES].getTextureRect().width));

	//locate:
	//Buttons
	m_buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width)*0.5, 
											  m_WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1.5 * 1));

	m_buttons[VIDEO_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.88, m_WINDOW_HEIGHT * 0.73));

	m_buttons[BACK].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.85, m_WINDOW_HEIGHT * 0.85));



	//Title
	m_TitleObjects[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));
	m_TitleObjects[PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.249, m_WINDOW_HEIGHT * 0.265));
	m_TitleObjects[DEMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.495, m_WINDOW_HEIGHT * 0.265));
	m_TitleObjects[HELLO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.14));
	m_TitleObjects[WANNA_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.65, m_WINDOW_HEIGHT * 0.15));
	m_TitleObjects[LETS_GO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.14));

	//Instructions:
	m_Instructions_Page[SHIR].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.80, m_WINDOW_HEIGHT * 0.40));
	m_Instructions_Page[EVIATAR1].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.2, m_WINDOW_HEIGHT * 0.35));
	m_Instructions_Page[EVIATAR2].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.07, m_WINDOW_HEIGHT * 0.73));
	m_Instructions_Page[SHIR_DROP].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.55, m_WINDOW_HEIGHT * 0.35));
	m_Instructions_Page[EVIATAR_DROP].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.15, m_WINDOW_HEIGHT * 0.35));
	m_Instructions_Page[OH_NO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.35, m_WINDOW_HEIGHT * 0));
	m_Instructions_Page[GAME_RULES].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.15, m_WINDOW_HEIGHT * 0.0));

}
