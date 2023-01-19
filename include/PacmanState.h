#pragma once

#include <SFML/Graphics.hpp>

class Door;

class PacmanState 
{

public:
    virtual ~PacmanState() = default;
    virtual void handleDoorCollision(int, Door&) =0;

private:
};

class SuperPacmanState : public PacmanState 
{
public:
    void handleDoorCollision(int keys, Door& door)
    {
      // door.SetCollide();
    }
};

class NormalPacman : public PacmanState
{
public:
    void handleDoorCollision(int keys, Door&) override
    {
        if (keys > 0)
        {
          //  door.SetCollide();
        }
    }
};
