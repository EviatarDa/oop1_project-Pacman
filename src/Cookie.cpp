#pragma once

#include "Cookie.h"

Cookie::Cookie()
{
	m_Texture.loadFromFile("Cookie.pnj");
	m_Sprite.setTexture(m_Texture);
}
