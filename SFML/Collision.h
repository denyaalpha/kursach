#pragma once
#include "SFML/Graphics.hpp"

class Collision {
	sf::Sprite& sprite;

public:
	Collision(sf::Sprite& sprite);
	bool checkCollision(Collision &other, float push, float time);
	sf::Vector2f getPosition();
	sf::Vector2f getHalfSize();
	void move(float dx, float dy);
};
