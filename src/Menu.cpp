#pragma once

#include "Menu.h"

Menu::Menu(int width, int height)
	:m_WINDOW_WIDTH(width), m_WINDOW_HEIGHT(height)
{
	//define the arrays:
	for (int button = PLAY; button <= BACK; button++)
	{
		m_Buttons[button].setTexture(Resources::instance().GetButton((Button)button));
	}

	for (int title = TITLE; title <= TITLE_DEAMONS; title++)
	{
		m_TitleObjects[title].setTexture(Resources::instance().GetTitle((Title)title));
	}

	for (int instruction = SHIR; instruction <= GAME_RULES; instruction++)
	{
		m_Instructions_Page[instruction].setTexture(Resources::instance().GetInstruction((Instructions)instruction));
	}

	m_Sound[CLICK].setBuffer(Resources::instance().GetSound(CLICK));

	//define the first visibility
	m_TitleObjects[HELLO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[WANNA_PLAY].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[LETS_GO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[TITLE_PACMAN].setColor(sf::Color::Color(255, 255, 255, 0));
	m_TitleObjects[TITLE_DEAMONS].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));
	SetPosition();
}

sf::Sprite Menu::GetButton(const Button object) const
{
	return m_Buttons[object];
}

sf::Sprite Menu::GetTitle(const Title object) const
{
	return m_TitleObjects[object];
}

sf::Sprite Menu::GetInstructions(const Instructions object) const
{
	return m_Instructions_Page[object];
}

void Menu::PlaySound(const Sound sound)
{
	m_Sound[sound].play();
}

void Menu::ButtonPress(const Button button)
{
	m_Buttons[button].setColor(sf::Color::Color(255, 255, 255, 150));
}

void Menu::ButtonRelease(const Button button)
{
	m_Buttons[button].setColor(sf::Color::Color(255, 255, 255));
}

void Menu::UpdateVisible(Title object, int& curr_brightness, const int add, const int brightness)
{
	curr_brightness += add;
	if ((curr_brightness > brightness && add > 0) || (curr_brightness < brightness && add < 0))
	{
		curr_brightness = brightness;
	}
	else
	{
		m_TitleObjects[object].setColor(sf::Color::Color(255, 255, 255, curr_brightness));
	}
}

void Menu::MoveObject(const Title object, const int x, const int y)
{
	m_TitleObjects[object].move(x, y);

}

void Menu::ResetLocation()
{
	m_TitleObjects[TITLE_PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.249, m_WINDOW_HEIGHT * 0.265));

	m_TitleObjects[TITLE_DEAMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.495, m_WINDOW_HEIGHT * 0.265));
}

void Menu::Mirror(const Title object)
{
	m_TitleObjects[object].scale(-1, 1);
}

void Menu::DisplayRules()
{
	m_Instructions_Page[EVIATAR1].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[OH_NO].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 255));
	m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 255));
	m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 255));
}

void Menu::DropTheMic()
{
	m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR_DROP].setColor(sf::Color::Color(255, 255, 255, 255));
	m_Instructions_Page[EVIATAR_DROP].setColor(sf::Color::Color(255, 255, 255, 255));
}

void Menu::ResetRules()
{
	m_Instructions_Page[EVIATAR1].setColor(sf::Color::Color(255, 255, 255, 255));
	m_Instructions_Page[OH_NO].setColor(sf::Color::Color(255, 255, 255, 255));

	m_Instructions_Page[SHIR].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR2].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[SHIR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[EVIATAR_DROP].setColor(sf::Color::Color(255, 255, 255, 0));
	m_Instructions_Page[GAME_RULES].setColor(sf::Color::Color(255, 255, 255, 0));
}

void Menu::SetPosition()
{
	//resize:
	//Buttons:
	m_Buttons[PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[PLAY].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_Buttons[PLAY].getTextureRect().width));

	m_Buttons[HELP].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[HELP].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_Buttons[HELP].getTextureRect().width));

	m_Buttons[EXIT].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.195 / m_Buttons[EXIT].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.195 / m_Buttons[EXIT].getTextureRect().width));

	m_Buttons[BACK].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.12 / m_Buttons[BACK].getTextureRect().width,
									   m_WINDOW_WIDTH * 0.12 / m_Buttons[BACK].getTextureRect().width));

	m_Buttons[VIDEO_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.05 / m_Buttons[VIDEO_PLAY].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.05 / m_Buttons[VIDEO_PLAY].getTextureRect().width));

	//Title:
	m_TitleObjects[TITLE].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.5 / m_TitleObjects[TITLE].getTextureRect().width));

	m_TitleObjects[HELLO].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.075 / m_TitleObjects[HELLO].getTextureRect().width,
											 m_WINDOW_WIDTH * 0.075 / m_TitleObjects[HELLO].getTextureRect().width));

	m_TitleObjects[WANNA_PLAY].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.1 / m_TitleObjects[WANNA_PLAY].getTextureRect().width,
												  m_WINDOW_WIDTH * 0.1 / m_TitleObjects[WANNA_PLAY].getTextureRect().width));

	m_TitleObjects[LETS_GO].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.075 / m_TitleObjects[LETS_GO].getTextureRect().width,
										   	   m_WINDOW_WIDTH * 0.075 / m_TitleObjects[LETS_GO].getTextureRect().width));

	m_TitleObjects[TITLE_PACMAN].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.053 / m_TitleObjects[TITLE_PACMAN].getTextureRect().width,
											  m_WINDOW_WIDTH * 0.053 / m_TitleObjects[TITLE_PACMAN].getTextureRect().width));

	m_TitleObjects[TITLE_DEAMONS].scale(sf::Vector2f(m_WINDOW_WIDTH * 0.257 / m_TitleObjects[TITLE_DEAMONS].getTextureRect().width,
											  m_WINDOW_WIDTH * 0.257 / m_TitleObjects[TITLE_DEAMONS].getTextureRect().width));

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
	m_Buttons[PLAY].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[PLAY].getTextureRect().width)*0.5, 
											  m_WINDOW_HEIGHT - m_Buttons[PLAY].getTextureRect().height * 1.5 * 3));

	m_Buttons[HELP].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[HELP].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_Buttons[HELP].getTextureRect().height * 1.5 * 2));

	m_Buttons[EXIT].setPosition(sf::Vector2f((m_WINDOW_WIDTH - m_Buttons[EXIT].getTextureRect().width) * 0.5,
											  m_WINDOW_HEIGHT - m_Buttons[EXIT].getTextureRect().height * 1.5 * 1));

	m_Buttons[VIDEO_PLAY].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.88, m_WINDOW_HEIGHT * 0.73));

	m_Buttons[BACK].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.85, m_WINDOW_HEIGHT * 0.85));



	//Title
	m_TitleObjects[TITLE].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.25, m_WINDOW_HEIGHT * 0.1));
	m_TitleObjects[TITLE_PACMAN].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.249, m_WINDOW_HEIGHT * 0.265));
	m_TitleObjects[TITLE_DEAMONS].setPosition(sf::Vector2f(m_WINDOW_WIDTH * 0.495, m_WINDOW_HEIGHT * 0.265));
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
