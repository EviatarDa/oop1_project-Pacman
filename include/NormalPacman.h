#pragma once

//#include "NormalPacman.h"
#include "PacmanState.h"
#include "Door.h"

class NormalPacman : public PacmanState
{
public:
    void handleDoorCollision(int keys, Door&, Pacman&, sf::Sound&);
    virtual void handleDeamonCollision(int, Deamon&, Pacman&);
};