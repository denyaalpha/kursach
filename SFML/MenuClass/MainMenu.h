#pragma once
#include "Menu.h"

class MainMenu : public Menu {
public:
	MainMenu(sf::Vector2f scale);
	void loadMenu() override;
};
