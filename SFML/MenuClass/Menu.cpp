#include "Menu.h"

Menu::Menu() {
	scale.x = scale.y = 1;
}

void Menu::increaseSound() {

}

void Menu::decreaseSound() {
}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < count; i++) {
		window.draw(buttons[i]);
		window.draw(menues[i]);
	}
}

void Menu::scroolUp() {
	if (target - 1 >= 0) {
		menues[target].setFillColor(sf::Color::White);
		target--;
		menues[target].setFillColor(sf::Color::Red);
	}
}

void Menu::scroolDown() {
	if (target + 1 < count) {
		menues[target].setFillColor(sf::Color::White);
		target++;
		menues[target].setFillColor(sf::Color::Red);
	}
}

int Menu::getTarget() const {
	return target;
}

int Menu::getSize() {
	return menues.size();
}

void Menu::setScale(sf::Vector2f scale) {
	this->scale = scale;
}

int Menu::getVolume() {
	return 0;
}