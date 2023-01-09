#pragma once

#include "Door.h"

Door::Door()
{
	m_Texture.loadFromFile("Door.pnj");
	m_Sprite.setTexture(m_Texture);
}
