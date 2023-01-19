#pragma once

#include "NormalPacman.h"

void NormalPacman::handleDoorCollision(int keys, Door& door, Pacman& pacman)
{
	if (keys > 0)
	{
		door.SetCollide();
		pacman.DecKeys();
	}
	else
	{
		pacman.SetLastLocation();
	}
}

void NormalPacman::handleDeamonCollision(int life, Deamon& deamon, Pacman& pacman) 
{
	pacman.SetToFirstLocation();
}
