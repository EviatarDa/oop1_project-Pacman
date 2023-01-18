#pragma once
#include "ToolBar.h"
#include <string>


ToolBar::ToolBar()
{
	//set the word:
	for (int word = LIFE; word <= TIME; word++)
	{
		m_toolbar[word].setFont(Resources::instance().GetFont());
		m_toolbar[word].setCharacterSize(30);
		m_toolbar[word].setString(m_Words[word]);
		m_toolbar[word].setPosition(20.f, word * 200.f);
	}
	//set the num:
	m_info_num[LIFE] = 3;
	m_info_num[SCORE] = 0;
	m_info_num[LEVEL] = 1;
	m_info_num[TIME] = 0;

	for (int word = LIFE; word <= TIME; word++)
	{
		m_Info[word].setFont(Resources::instance().GetFont());
		m_Info[word].setCharacterSize(30);
		m_Info[word].setString(std::to_string(m_info_num[word]));
		m_Info[word].setPosition(40.f,40 + word * 200.f);
	}
}

sf::Text& ToolBar::GetText(int word)
{
	return m_toolbar[word];

}

sf::Text& ToolBar::GetNum(int num )
{
	return m_Info[num];
}
