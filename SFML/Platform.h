#pragma once
#include "SFML/Graphics.hpp"
#include "Collision.h"

class Platform {
	sf::Sprite sprite;

public:
	Platform();
	void draw(sf::RenderWindow& window);
	Collision getCollider();
	sf::Sprite &getSprite();
	void setPlatform(sf::Texture& texture, sf::IntRect rectangle, sf::Vector2f size, sf::Vector2f &position);
};

