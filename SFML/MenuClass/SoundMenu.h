#pragma once
#include "Menu.h"

class SoundMenu : public Menu {
	sf::RectangleShape sound, not_sound;
	int empty;
	int full;
	int volume;

	void updateBar();
	void updatePositionAndSize();
public:
	SoundMenu(sf::Vector2f scale);
	void loadMenu() override;
	void draw(sf::RenderWindow& window) override;
	void increaseSound();
	void decreaseSound();
	int getVolume() override;
};

