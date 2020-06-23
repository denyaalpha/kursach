#include "Platform.h"

Platform::Platform()
{
}

void Platform::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

Collision Platform::getCollider() {
	return Collision(sprite);
}

void Platform::setPlatform(sf::Texture &texture, sf::IntRect rectangle, sf::Vector2f size, sf::Vector2f& position) {
	sprite.setTexture(texture);
	sprite.setTextureRect(rectangle);
	sprite.setPosition(position);
}
