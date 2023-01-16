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

	for (int title = TITLE; title <= DEMONS; title++)
	{
		m_TitleTextures[title].loadFromFile(m_TitleFiles[title]);
		m_TitleTextures[title].setSmooth(true);

	}

	for (int instruction = SHIR; instruction <= GAME_RULES; instruction++)
	{
		m_InstructionsTextures[instruction].loadFromFile(m_InstructionFiles[instruction]);
		m_InstructionsTextures[instruction].setSmooth(true);
	}
	m_song.loadFromFile("Song.ogg");
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

sf::SoundBuffer& Resources::getsong()
{
	return m_song;
}