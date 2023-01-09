#pragma once

#include "Wall.h"

Wall::Wall()
{
	m_Texture.loadFromFile("Wall.pnj");
	m_Sprite.setTexture(m_Texture);
}
