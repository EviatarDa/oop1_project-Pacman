#pragma once

#include "Menu.h"

Menu::Menu()
{
	
	m_BackGroung.loadFromFile("PacmanMenuBackground.png");
	m_BackGroung.setSmooth(true);
	m_buttons[BACKGROUND].setTexture(m_BackGroung);

	
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
	m_buttons[BACKGROUND].setPosition(sf::Vector2f(370, 80));
	m_buttons[BACKGROUND].scale(sf::Vector2f(2.f, 2.f));
	m_buttons[PLAY].setPosition(sf::Vector2f(550, 500));
	m_buttons[HELP].setPosition(sf::Vector2f(550, 590));
	m_buttons[EXIT].setPosition(sf::Vector2f(550, 680));
}
