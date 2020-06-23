#pragma once
#include "Person.h"

class MainHero : public Person {
	void updateMovement(int dir, float time);
public:
	MainHero();
	void moveUp(float time);
	void moveDown(float time);
	void moveLeft(float time);
	void moveRight(float time);
	void updateCoords();
	sf::Vector2f getPosition();
	Collision getCollider();
	sf::RectangleShape &getBody();
};

