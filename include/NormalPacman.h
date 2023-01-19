#pragma once
#include "NormalPacman.h"
#include "Door.h"

class NormalPacman : public PacmanState
{
public:
    void handleDoorCollision(int keys, Door&) override;

};