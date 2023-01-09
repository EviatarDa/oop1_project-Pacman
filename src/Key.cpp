#pragma once

#include "Key.h"

Key::Key()
{
	m_Texture.loadFromFile("Key.pnj");
	m_Sprite.setTexture(m_Texture);
}
