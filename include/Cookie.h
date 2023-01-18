#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Deamon.h"

class Cookie :public StaticObjects
{
public:
	Cookie(const int, const int, const int, const int, Object);
    virtual void HandleCollision(GameObject&)override;
    virtual void HandleCollision(Pacman&)override;
    virtual void HandleCollision(Deamon&)override;
    virtual void HandleCollision(Wall&)override;
    virtual void HandleCollision(Door&)override;
    virtual void HandleCollision(Key&)override;
    virtual void HandleCollision(Present&)override;
    virtual void HandleCollision(Cookie&)override;


private:
};