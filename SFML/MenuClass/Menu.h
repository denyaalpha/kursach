#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include <fstream>
//Menu  => Main Menu
//		=> Options
//		=> GameMenu
//abstract class

class Menu {
protected:
	sf::Font font;
	int count;
	int target;
	std::string filename;
	std::vector<sf::Text> menues;
	std::vector<sf::RectangleShape> buttons;
	sf::Vector2f scale;

public:
	Menu();
	virtual void loadMenu() = 0;
	virtual void increaseSound();
	virtual void decreaseSound();
	virtual void draw(sf::RenderWindow& window);
	void scroolUp();
	void scroolDown();
	int getTarget() const;
	int getSize();
	void setScale(sf::Vector2f scale);
	virtual int getVolume();
};

