
#include "SuperPacmanState.h"
#include "Door.h"

void SuperPacmanState::handleDoorCollision(int keys, Door& door)
{
    door.SetCollide();
}