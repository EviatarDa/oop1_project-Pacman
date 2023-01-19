#pragma once

#include <SFML/Graphics.hpp>

class Door;
class Pacman;

//#pragma once

//#include 

class PacmanState 
{

public:
    virtual ~PacmanState() = default;
    virtual void handleDoorCollision(int, Door&, Pacman&) =0;
    //virtual void handleDeamonCollision(int, Deamon&, Pacman&) =0;

private:
};




