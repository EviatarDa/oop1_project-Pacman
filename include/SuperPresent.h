#pragma once

#include "Present.h"
#include <SFML/Graphics.hpp>

class SuperPresent : public Present
{
public:
    SuperPresent(const int, const int, const int, const int, Object);
     void HandleCollision(Pacman&)override;

private:

};
