#pragma once

#include "SuperPacmanState.h"
#include "Door.h"

void SuperPacmanState::handleDoorCollision(int keys, Door& door, Pacman&, sf::Sound& DoorSound)
{
    //super can open doors
    door.SetCollide();
    DoorSound.play();
}