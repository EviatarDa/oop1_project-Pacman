#pragma once

#include "Resources.h"

Resources::Resources()
{
	LoadFromFile();
}

Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}


void Resources::LoadFromFile()
{
	for (int button = PLAY; button <= BACK; button++)
	{
		m_ButtonTextures[button].loadFromFile(m_ButtonFiles[button]);
		m_ButtonTextures[button].setSmooth(true);
	}

	for (int title = TITLE; title <= TITLE_DEAMONS; title++)
	{
		m_TitleTextures[title].loadFromFile(m_TitleFiles[title]);
		m_TitleTextures[title].setSmooth(true);

	}

	for (int instruction = SHIR; instruction <= GAME_RULES; instruction++)
	{
		m_InstructionsTextures[instruction].loadFromFile(m_InstructionFiles[instruction]);
		m_InstructionsTextures[instruction].setSmooth(true);
	}

	for (int object = PACMAN; object <= ADD_TIME; object++)
	{
		m_GameObjectTextures[object].loadFromFile(m_GameObjectFiles[object]);
		m_GameObjectTextures[object].setSmooth(true);
	}

	for (int sound = SONG; sound <= GAME_OVER; sound++)
	{
		m_Sounds[sound].loadFromFile(m_SoundFiles[sound]);
	}
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

}

sf::Texture& Resources::GetButton(Button button)
{
	return m_ButtonTextures[button];
}

sf::Texture& Resources::GetTitle(Title title)
{
	return m_TitleTextures[title];
}

sf::Texture& Resources::GetInstruction(Instructions instruction)
{
	return m_InstructionsTextures[instruction];
}

sf::Texture& Resources::GetGameObject(Object object)
{
	return m_GameObjectTextures[object];
}

sf::SoundBuffer& Resources::GetSound(Sound sound)
{
	return m_Sounds[sound];
}

sf::Font& Resources::GetFont()
{
	return m_font;
}