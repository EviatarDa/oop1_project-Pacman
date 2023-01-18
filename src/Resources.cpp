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

	for (int object = PACMAN; object <= PRESENT; object++)
	{
		m_GameObjectTextures[object].loadFromFile(m_GameObjectFiles[object]);
		m_GameObjectTextures[object].setSmooth(true);
	}


	m_song.loadFromFile("Song.ogg");
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

sf::SoundBuffer& Resources::getsong()
{
	return m_song;
}

sf::Font& Resources::GetFont()
{
	return m_font;
}