#include "Text.h"

Text::Text() {
	str = "";
}

void Text::setFont(const std::string& fontName) {
	if (!font.loadFromFile("Font/" + fontName + ".ttf"))
		std::cout << "Error" << std::endl;
	text.setFont(font);
}

void Text::setText(const std::string& str) {
	this->str = str;
	text.setString(str);
}

void Text::addLetter(char letter) {
	setText(str + letter);
}

void Text::removeBackLetter() {
	str.pop_back();
	setText(str);
}

void Text::removeFrontLetter() {
	str.erase(str[0]);
	setText(str);
}

void Text::setColor(const sf::Color& color) {
	text.setFillColor(color);
}

void Text::setPosition(sf::Vector2f position) {
	text.setPosition(position);
}

void Text::setScale(sf::Vector2f scale) {
	text.scale(scale.x, scale.y);
}

void Text::clearText() {
	setText("");
}

bool Text::setTextFromFile(const std::string& filename) {
	std::ifstream a(filename + ".txt");
	if (!a.is_open()) {
		std::cout << "Cannot open" << std::endl;
	}

	getline(a, str);
	std::cout << str << std::endl;
	return true;
}

sf::Text& Text::getText() {
	return text;
}
