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
	m_Hello.loadFromFile("Hello.png");
	m_WannaPlay.loadFromFile("WannaPlay.png");
	m_LetsGo.loadFromFile("LetsGo.png");
	m_Pacman.loadFromFile("Pacman-Title.png"); //new
	m_Demons.loadFromFile("Demons-Title.png"); //new
	m_Instructions.loadFromFile("Instructions.png");


	//make it looks good
	m_Title.setSmooth(true);
	m_Instructions.setSmooth(true);
	m_Pacman.setSmooth(true);

	//define the array:
	m_buttons[VIDEO_PLAY].setTexture(m_VideoPlay);
	m_buttons[PLAY].setTexture(m_Play);
	m_buttons[HELP].setTexture(m_Help);
	m_buttons[EXIT].setTexture(m_Exit);

	m_TitleObjects[TITLE].setTexture(m_Title);
	m_TitleObjects[HELLO].setTexture(m_Hello);
	m_TitleObjects[WANNA_PLAY].setTexture(m_WannaPlay);
	m_TitleObjects[LETS_GO].setTexture(m_LetsGo);
	m_TitleObjects[PACMAN].setTexture(m_Pacman);
	m_TitleObjects[DEMONS].setTexture(m_Demons);

	m_Instructions_Page[INSTRUCTION].setTexture(m_Instructions);

	//define the first visibility
	m_TitleObjects[HELLO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[WANNA_PLAY].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[LETS_GO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[PACMAN].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[DEMONS].setColor(sf::Color::Color(255, 255, 255, 0));

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

void Menu::UpdateVisible(const Title object, int &visibility, int amount)
{
	visibility += amount;
	if (visibility > 255)
	{
		visibility = 255;
	}
	else if (visibility < 0)
	{
		visibility = 0;
	}
	m_TitleObjects[object].setColor(sf::Color::Color(255, 255, 255, visibility));
}

void Menu::UpdateLocation(const Title object, int move)
{
	m_TitleObjects[object].move(move,0);

}

void Menu::ResetLocation()
{
	m_TitleObjects[PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.27));

	m_TitleObjects[DEMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.50, m_WINDOW_HEIGHT * 0.27));
}

void Menu::Mirror(const Title object)
{
	m_TitleObjects[object].scale(-1, 1);
}

void Menu::SetPosition()
{
	//resize:
	//Buttons:
	m_buttons[VIDEO_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width));

	m_buttons[PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width));

	m_buttons[HELP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width));

	m_buttons[EXIT].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width));

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

	m_TitleObjects[DEMONS].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.26 / m_TitleObjects[DEMONS].getTextureRect().width,
											  m_WINDOW_WIDTH * 0.26 / m_TitleObjects[DEMONS].getTextureRect().width));

	//Instructions:
	m_Instructions_Page[INSTRUCTION].scale(sf::Vector2f(m_WINDOW_WIDTH / m_Instructions_Page[INSTRUCTION].getTextureRect().width,
													    m_WINDOW_WIDTH / m_Instructions_Page[INSTRUCTION].getTextureRect().width));

	//locate:
	//Buttons
	m_buttons[VIDEO_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.63, m_WINDOW_HEIGHT * 0.48));

	m_buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width)*0.5, 
											  m_WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1.5 * 1));

	//Title
	m_TitleObjects[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));

	m_TitleObjects[PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.27));

	m_TitleObjects[DEMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.493, m_WINDOW_HEIGHT * 0.27));

	m_TitleObjects[HELLO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.14));

	m_TitleObjects[WANNA_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.65, m_WINDOW_HEIGHT * 0.15));

	m_TitleObjects[LETS_GO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.14));


}
