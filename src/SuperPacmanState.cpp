#pragma once

#include "SuperPacmanState.h"
#include "Door.h"

void SuperPacmanState::handleDoorCollision(int keys, Door& door, Pacman&, sf::Sound& DoorSound)
{
    door.SetCollide();
    DoorSound.play();
}