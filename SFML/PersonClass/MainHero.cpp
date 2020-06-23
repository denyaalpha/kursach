#include "MainHero.h"
//speed = 0.05
//0.004*tme

void MainHero::updateMovement(int dir, float time) {
	speed = 2;

	currentFrame += 0.004 * time;
	if (currentFrame > 3) 
		currentFrame -= 3;

	switch (dir) {
	case 3: dx_vector.x = speed; dx_vector.y = 0; break;
	case 2: dx_vector.x = -speed; dx_vector.y = 0; break;
	case 1: dx_vector.x = 0; dx_vector.y = speed; break;
	case 0: dx_vector.x = 0; dx_vector.y = -speed; break;
	}
	sprite.setTextureRect(sf::IntRect(32 * dir , 32 * int(currentFrame), 32, 32));

	coordinates.x += (dx_vector.x);
	coordinates.y += (dx_vector.y);

	sprite.move(dx_vector.x, dx_vector.y);
}

MainHero::MainHero() :
	Person("MainHero", sf::Vector2f(0,0), sf::Vector2f(32,32)) {
	currentFrame = 0;
	coordinates = { 0,0 };
	sprite.setPosition(coordinates);
	body.setFillColor(sf::Color::Black);
}

void MainHero::moveUp(float time) {
	updateMovement(0, time);
}

void MainHero::moveDown(float time) {
	updateMovement(1, time);
}

void MainHero::moveLeft(float time) {
	updateMovement(2, time);
}

void MainHero::moveRight(float time) {
	updateMovement(3, time);
}

void MainHero::updateCoords() {
	coordinates.x = sprite.getPosition().x;
	coordinates.y = sprite.getPosition().y;
}

sf::Vector2f MainHero::getPosition() {
	return coordinates;
}

Collision MainHero::getCollider() {
	return Collision(sprite);
}

sf::RectangleShape& MainHero::getBody() {
	return body;
}
