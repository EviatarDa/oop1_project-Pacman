#pragma once

#include "ToolBar.h"
#include <iostream>


ToolBar::ToolBar()
{
	//set the word:
	for (int word = LIFE; word <= KEYCOUNTER; word++)
	{
		m_toolbar[word].setFont(Resources::instance().GetFont());
		m_toolbar[word].setCharacterSize(30);
		m_toolbar[word].setString(m_Words[word]);
		m_toolbar[word].setPosition(10.f, word * 150.f+10);
	}
	//set the num:
	m_info_num[LIFE] = 3;
	m_info_num[SCORE] = 0;
	m_info_num[LEVEL] = 1;
	m_info_num[TIME] = 0;
	m_info_num[KEYCOUNTER] = 0;

	for (int word = LIFE; word <= KEYCOUNTER; word++)
	{
		m_Info[word].setFont(Resources::instance().GetFont());
		m_Info[word].setCharacterSize(30);
		m_Info[word].setString(std::to_string(m_info_num[word]));
		m_Info[word].setPosition(30.f,40 + word * 150.f+10);
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

void ToolBar::SetLife(const int life)
{
	m_info_num[LIFE] = life;
	m_Info[LIFE].setString(std::to_string(life));
}

void ToolBar::SetScore(const int score)
{
	m_info_num[SCORE] = score;
	m_Info[SCORE].setString(std::to_string(score));
}

void ToolBar::SetLevel(const int level)
{
	m_info_num[LEVEL] = level;
	m_Info[LEVEL].setString(std::to_string(level));
}

void ToolBar::SetKeys(const int keys)
{
	m_info_num[KEYCOUNTER] = keys;
	m_Info[KEYCOUNTER].setString(std::to_string(keys));
}

void ToolBar::SetTime(const int time)
{
	m_info_num[TIME] = 120 - time;
	m_Info[TIME].setString(std::to_string(m_info_num[TIME]));
}

int ToolBar::GetScore()
{
	return m_info_num[SCORE];
}

int ToolBar::GetLife()
{
	return m_info_num[LIFE];
}
