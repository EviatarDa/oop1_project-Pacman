#pragma once

#include "Present.h"
#include <SFML/Graphics.hpp>

class AddTime : public Present
{
public:
	AddTime(const int, const int, const int, const int, Object objet);
	void HandleCollision(Pacman&)override;


private:

};

