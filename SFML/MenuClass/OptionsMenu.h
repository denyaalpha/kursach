#pragma once
#include "Menu.h"

class OptionsMenu : public Menu {
	bool isFullscreen;

public:
	OptionsMenu(sf::Vector2f scale, bool isFullscreen);
	void loadMenu() override;
	void updateInfo();
};