#pragma once

#include "Menu.h"

Menu::Menu(int width, int height)
	:m_WINDOW_WIDTH(width), m_WINDOW_HEIGHT(height)
{
	m_BackGround.loadFromFile("PacmanMenuBackground.png");
	m_BackGround.setSmooth(true);
	m_buttons[BACKGROUND].setTexture(m_BackGround);

	
	m_Play.loadFromFile("yellow.png");
	m_buttons[PLAY].setTexture(m_Play);

	m_Help.loadFromFile("blue.png");
	m_buttons[HELP].setTexture(m_Help);
	
	m_Exit.loadFromFile("red.png");
	m_buttons[EXIT].setTexture(m_Exit);

	SetPosition();
}

sf::Sprite Menu::GetSprite(const button index) const
{
	return m_buttons[index];
}



void Menu::SetPosition()
{
	m_buttons[BACKGROUND].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_buttons[BACKGROUND].getTextureRect().width, 
										     m_WINDOW_WIDTH * 0.5 / m_buttons[BACKGROUND].getTextureRect().width));
	m_buttons[BACKGROUND].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));
	
	m_buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width)*0.5, 
											m_WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
											m_WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
											m_WINDOW_HEIGHT- m_buttons[EXIT].getTextureRect().height*1.5*1));
}
