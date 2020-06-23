#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include <string>

class Man {
protected:
	float x, y;
	float width, height;
	float dx, dy;
	float speed;
	int direction;
	std::string file;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape body;

public:
	Man() = default;
	Man(std::string file, float x, float y, float width, float height);
	void setInfo(std::string file, float x, float y, float width, float height); //added
	void update(float time);
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	void setX(float x);
	void setY(float y);
	float getSpeed() const;
	void setSpeed(float speed);
	void setDirection(int direction);
	int getDirection() const;
	void changeFrame(int curFrame);
	sf::Sprite getSprite() const;
	void interactionWithMap();
};

