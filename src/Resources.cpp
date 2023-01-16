#pragma once
#include "Resources.h"

Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}


void Resources::loadfromfile()
{
	/*m_Textures[1].loadFromFile();
	m_Textures[2].loadFromFile();
	m_Textures[3].loadFromFile();
	m_Textures[4].loadFromFile();
	m_Textures[5].loadFromFile();
	m_Textures[6].loadFromFile();
	m_Textures[7].loadFromFile();
	m_Textures[8].loadFromFile();*/
	m_song.loadFromFile("Song.ogg");
}

sf::Texture Resources::gettexture(int type)
{
	return m_Textures[type];
}

sf::SoundBuffer Resources::getsong()
{
	return m_song;
}