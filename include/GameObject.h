#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class Pacman;
class Deamon;
class Wall;
class Door;
class Key;
class SuperPresent;
class AddTime;
class Freeze;
class AddLife;
class Cookie;


class GameObject
{
public:
	GameObject(const int, const int, const int, const int, Object);
	virtual ~GameObject() = default;
	sf::Sprite& GetSprite();
	bool CheckCollision(const GameObject&)const;
	const bool GetIsCollide()const;

	virtual void HandleCollision(GameObject&) = 0;
	virtual void HandleCollision(Pacman&) = 0;
	virtual void HandleCollision(Deamon&) = 0;
	virtual void HandleCollision(Wall&) = 0;
	virtual void HandleCollision(Door&) = 0;
	virtual void HandleCollision(Key&) = 0;
	virtual void HandleCollision(SuperPresent&) = 0;
	virtual void HandleCollision(AddTime&) = 0;
	virtual void HandleCollision(Freeze&) = 0;
	virtual void HandleCollision(AddLife&) = 0;
	virtual void HandleCollision(Cookie&) = 0;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_last_location;
	sf::Vector2f m_first_location;
	bool m_IsCollide = false;

private:
	
};