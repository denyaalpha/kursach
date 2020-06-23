#pragma once
#include "SFML/Graphics.hpp"
#include "../Collision.h"

class Person {
protected:
	float hp;
	sf::Vector2f coordinates;
	sf::Vector2f size;
	sf::Vector2f dx_vector; //dx_vector = (dx,dy)^T
	float speed;
	int direction;
	std::string filename;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape body;
	float currentFrame;

public:
	Person(std::string filename, sf::Vector2f coordinates, sf::Vector2f size);
	sf::Vector2f getCoordinates() const;
	void setCoordinates(sf::Vector2f coordinates);
	float getSpeed() const;
	void setSpeed(float speed);
	void changeFrame(int curFrame);
	void draw(sf::RenderWindow& window);
};

