#include "Collision.h"

Collision::Collision(sf::Sprite &sprite) : sprite(sprite) {
}

bool Collision::checkCollision(Collision &other, float push, float time) {
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();

	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = fabs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = fabs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				move(intersectX * (1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else {
				move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				move(0.0f, intersectY * (1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else {
				move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}
		return true;
	}
	
	return false;
}

sf::Vector2f Collision::getPosition() {
	return sprite.getPosition();
}

sf::Vector2f Collision::getHalfSize() {
	return sf::Vector2f(16,16);
}

void Collision::move(float dx, float dy) {
	sprite.move(dx, dy);
}
