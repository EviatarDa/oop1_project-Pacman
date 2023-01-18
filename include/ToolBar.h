#pragma once
#include <SFML/Graphics/Text.hpp>
#include "Resources.h"

class ToolBar
{
public:
	ToolBar();
	sf::Text& GetText(int);
	sf::Text& GetNum(int);



private:
	sf::Text m_toolbar[TOOL_BAR];
	sf::Text m_Info[TOOL_BAR];
	std::string m_Words[TOOL_BAR] = { "Life:" , "Score:", "Level:", "Time:" };
	int m_info_num[TOOL_BAR];
	

};