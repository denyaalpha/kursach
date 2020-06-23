#include "Person.h"

Person::Person(std::string filename, sf::Vector2f coordinates, sf::Vector2f size) {
	this->filename = filename;
	this->coordinates = coordinates;
	this->size = size;
	image.loadFromFile("Person/" + filename + ".png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	sprite.setPosition(coordinates);
	body.setSize(sf::Vector2f(32, 32));
	coordinates = { 0,0 };
	dx_vector = { 0,0 };
}

sf::Vector2f Person::getCoordinates() const {
	return coordinates;
}

void Person::setCoordinates(sf::Vector2f coordinates) {
	this->coordinates = coordinates;
}

float Person::getSpeed() const {
	return speed;
}

void Person::setSpeed(float speed) {
	this->speed = speed;
}

void Person::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
