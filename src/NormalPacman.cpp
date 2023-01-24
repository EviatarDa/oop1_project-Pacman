#pragma once

#include "NormalPacman.h"

void NormalPacman::handleDoorCollision(int keys, Door& door, Pacman& pacman, sf::Sound& DoorSound)
{
	//open the door if pacman have keys
	if (keys > 0)
	{
		door.SetCollide();
		pacman.DecKeys();
		DoorSound.play();
	}
	else
	{
		pacman.SetLastLocation();
	}
}

void NormalPacman::handleDeamonCollision(int life, Deamon& deamon, Pacman& pacman) 
{
	pacman.SetToFirstLocation();
	pacman.SetLife(); // minus life
}
