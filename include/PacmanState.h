#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Door;
class Pacman;
class Deamon;

//#pragma once

//#include 

class PacmanState 
{

public:
    virtual ~PacmanState() = default;
    virtual void handleDoorCollision(int, Door&, Pacman&, sf::Sound&) =0;
    virtual void handleDeamonCollision(int, Deamon&, Pacman&) =0;

private:
};




