#pragma once

#include "PacmanState.h"

class SuperPacmanState : public PacmanState
{
public:
    void handleDoorCollision(int keys, Door& door, Pacman&);
};