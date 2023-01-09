#pragma once

#include "Present.h"

Present::Present()
{
	m_Texture.loadFromFile("Present.pnj");
	m_Sprite.setTexture(m_Texture);
}
