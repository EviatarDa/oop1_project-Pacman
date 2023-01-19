#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
//#include "StaticObjects.h"
//#include "MovingObject.h"

class Pacman;
class Deamon;
class Wall;
class Door;
class Key;
class Present;
class Cookie;


class GameObject
{
public:
	GameObject(const int, const int, const int, const int, Object);
	sf::Sprite& GetSprite();
	bool CheckCollision(const GameObject&)const;

	virtual void HandleCollision(GameObject&) = 0;
	virtual void HandleCollision(Pacman&) = 0;
	virtual void HandleCollision(Deamon&) = 0;
	virtual void HandleCollision(Wall&) = 0;
	virtual void HandleCollision(Door&) = 0;
	virtual void HandleCollision(Key&) = 0;
	virtual void HandleCollision(Present&) = 0;
	virtual void HandleCollision(Cookie&) = 0;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_last_location;

private:
};