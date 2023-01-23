#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Deamon.h"

class Present :public StaticObjects
{
public:
	Present(const int, const int, const int, const int, Object);
    virtual void HandleCollision(GameObject&)override;
    virtual void HandleCollision(Pacman&) = 0;
    virtual void HandleCollision(Deamon&)override;
    virtual void HandleCollision(Wall&)override;
    virtual void HandleCollision(Door&)override;
    virtual void HandleCollision(Key&)override;
    virtual void HandleCollision(SuperPresent&)override;
    virtual void HandleCollision(AddTime&)override;
    virtual void HandleCollision(Freeze&)override;
    virtual void HandleCollision(AddLife&)override;
    virtual void HandleCollision(Cookie&)override;

private:

};