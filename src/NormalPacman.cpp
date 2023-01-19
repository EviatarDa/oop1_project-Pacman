#include "NormalPacman.h"

void NormalPacman::handleDoorCollision(int /*keys*/, Door& door)
{
	door.SetCollide();
}
