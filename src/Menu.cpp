#pragma once

#include "Menu.h"

Menu::Menu(int width, int height)
	:m_WINDOW_WIDTH(width), m_WINDOW_HEIGHT(height)
{
	m_Title.loadFromFile("title.png");
	m_Title.setSmooth(true);
	m_buttons[TITLE].setTexture(m_Title);

	
	m_Play.loadFromFile("Play.png");
	m_buttons[PLAY].setTexture(m_Play);

	m_Help.loadFromFile("Help.png");
	m_buttons[HELP].setTexture(m_Help);
	
	m_Exit.loadFromFile("Exit.png");
	m_buttons[EXIT].setTexture(m_Exit);

	SetPosition();
}

sf::Sprite Menu::GetSprite(const button index) const
{
	return m_buttons[index];
}



void Menu::SetPosition()
{
	m_buttons[TITLE].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_buttons[TITLE].getTextureRect().width,
										     m_WINDOW_WIDTH * 0.5 / m_buttons[TITLE].getTextureRect().width));
	m_buttons[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));
	
	m_buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[PLAY].getTextureRect().width)*0.5, 
											m_WINDOW_HEIGHT - m_buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[HELP].getTextureRect().width) * 0.5,
											m_WINDOW_HEIGHT - m_buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_buttons[EXIT].getTextureRect().width) * 0.5,
											m_WINDOW_HEIGHT - m_buttons[EXIT].getTextureRect().height * 1.5 * 1));
}
