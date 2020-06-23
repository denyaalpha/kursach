#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Text {
protected:
	sf::Font font;
	sf::Text text;
	std::string str;

public:
	Text();
	void setFont(const std::string& fontName);
	void setText(const std::string& str);
	void addLetter(char letter);
	void removeBackLetter();
	void removeFrontLetter();
	void setColor(const sf::Color& color);
	void setPosition(sf::Vector2f position);
	void setScale(sf::Vector2f scale);
	void clearText();
	bool setTextFromFile(const std::string &filename);
	sf::Text& getText();
};

