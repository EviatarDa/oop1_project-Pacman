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
	m_Pacman.loadFromFile("Pacman-Title.png"); //new
	m_Demons.loadFromFile("Demons-Title.png"); //new
	m_Instructions.loadFromFile("Instructions.png");


	//make it looks good
	m_Title.setSmooth(true);
	m_Instructions.setSmooth(true);
	m_Pacman.setSmooth(true);

	//define the array
	m_buttons[TITLE].setTexture(m_Title);
	m_buttons[VIDEO_PLAY].setTexture(m_VideoPlay);
	m_buttons[PLAY].setTexture(m_Play);
	m_buttons[HELP].setTexture(m_Help);
	m_buttons[EXIT].setTexture(m_Exit);
	m_buttons[HELLO].setTexture(m_Hello);
	m_buttons[WANNA_PLAY].setTexture(m_WannaPlay);
	m_buttons[PACMAN].setTexture(m_Pacman);//new
	m_buttons[DEMONS].setTexture(m_Demons);//new
	m_buttons[INSTRUCTIONS].setTexture(m_Instructions);

	//define the first visibility
	m_buttons[HELLO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_buttons[WANNA_PLAY].setColor(sf::Color::Color(255, 255, 255, 0));

	SetPosition();
}

sf::Sprite Menu::GetSprite(const Button index) const
{
	return m_buttons[index];
}

void Menu::ButtonPress(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

void Menu::ButtonRelease(const Button button)
{
	m_buttons[button].setColor(sf::Color::Color(255, 255, 255));
}

void Menu::UpdateVisible(const Button button, int &visibility)
{
	if (visibility < 255)
	{
		visibility += 5;
		m_buttons[button].setColor(sf::Color::Color(255, 255, 255, visibility));
	}
}

void Menu::Mirror(const Button button)
{
	m_buttons[button].scale(-1, 1);
	m_buttons[button].setOrigin(m_buttons[button].getTextureRect().width, 0);
}

void Menu::SetPosition()
{
	//resize:
	m_buttons[TITLE].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_buttons[TITLE].getTextureRect().width,
										m_WINDOW_WIDTH * 0.5 / m_buttons[TITLE].getTextureRect().width));

	m_buttons[VIDEO_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.05 / m_buttons[VIDEO_PLAY].getTextureRect().width));

	m_buttons[PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[PLAY].getTextureRect().width));

	m_buttons[HELP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[HELP].getTextureRect().width));

	m_buttons[EXIT].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_buttons[EXIT].getTextureRect().width));

	m_buttons[HELLO].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.075 / m_buttons[HELLO].getTextureRect().width,
										m_WINDOW_WIDTH * 0.075 / m_buttons[HELLO].getTextureRect().width));

	m_buttons[WANNA_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.1 / m_buttons[WANNA_PLAY].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.1 / m_buttons[WANNA_PLAY].getTextureRect().width));

	m_buttons[INSTRUCTIONS].scale(sf::Vector2f(m_WINDOW_WIDTH / m_buttons[INSTRUCTIONS].getTextureRect().width,
										 	   m_WINDOW_WIDTH / m_buttons[INSTRUCTIONS].getTextureRect().width));

	m_buttons[PACMAN].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.053 / m_buttons[PACMAN].getTextureRect().width,
										 m_WINDOW_WIDTH * 0.053 / m_buttons[PACMAN].getTextureRect().width));

	m_buttons[DEMONS].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.25 / m_buttons[DEMONS].getTextureRect().width,
										 m_WINDOW_WIDTH * 0.25 / m_buttons[DEMONS].getTextureRect().width));

	//locate:
	m_buttons[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));

	m_buttons[VIDEO_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.75, m_WINDOW_HEIGHT * 0.25));

	m_buttons[PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.27));

	m_buttons[DEMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.75, m_WINDOW_HEIGHT * 0.27));

	m_buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width)*0.5, 
											  m_WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1.5 * 1));

	m_buttons[HELLO].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.14));
	m_buttons[WANNA_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.65, m_WINDOW_HEIGHT * 0.15));
}
