#pragma once

#include "Present.h"
#include <SFML/Graphics.hpp>

class Freeze : public Present
{
public:
	Freeze(const int, const int, const int, const int, Object);
	void HandleCollision(Pacman&)override;

private:

};
