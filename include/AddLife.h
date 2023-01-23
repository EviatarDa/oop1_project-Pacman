#pragma once

#include "Present.h"
#include <SFML/Graphics.hpp>

class AddLife : public Present
{
public:
	AddLife(const int , const int , const int , const int , Object );
	void HandleCollision(Pacman&)override;


private:

};
