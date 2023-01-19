#pragma once

#include <SFML/Graphics.hpp>

class Door;

#pragma once

//#include 

class PacmanState 
{

public:
    virtual ~PacmanState() = default;
    virtual void handleDoorCollision(int, Door&) =0;

private:
};




