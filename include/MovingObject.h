#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class MovingObject :public GameObject
{
public:
	MovingObject(const int, const int, const int, const int, Object);
	sf::Vector2f DirectionToVector(Direction);
	virtual void UpdateDirection(sf::Vector2f) = 0;
	virtual void Move(sf::Time) = 0;
	void SetToFirstLocation();
	virtual int GetScore() { return 0; };
	virtual int GetLife() { return 0; };
	virtual int GetKeys() { return 0; };
	virtual int GetEatten() { return 0; };
	virtual void SetCookies() {};
	virtual void UpdateState(bool, int&) = 0;
	bool GetFreeze();
	bool GetResetLocation();
	void SetResetLocation();
	void ResetLocation();
	virtual void SetLife(int) {};
	virtual void SetScore(int) {};

protected:
	bool m_freeze = false;
	bool m_reset_location = false;

private:

};
