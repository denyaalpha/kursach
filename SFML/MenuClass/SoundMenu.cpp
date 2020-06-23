#include "SoundMenu.h"

void SoundMenu::updateBar() {
	std::string newBar = "";
	for (int i = 0; i < full; i++)
		newBar += '#';
	for (int i = full; i < 10; i++)
		newBar += ' ';

	std::ofstream save("Menu (EN)/Settings/Sound/musicVolume.txt");
	if (!save.is_open()) {
		std::cout << "Cannot update sound:c" << std::endl;
		return;
	}
	save << newBar;
	save.close();
}

void SoundMenu::updatePositionAndSize() {
	sound.setPosition(sf::Vector2f(200 * scale.x, 300 * scale.y));
	not_sound.setPosition(sf::Vector2f(scale.x * (200 + 40 * full), 300 * scale.y));
	sound.setSize(sf::Vector2f(40 * full, 44));
	not_sound.setSize(sf::Vector2f(40 * empty, 44));
}

SoundMenu::SoundMenu(sf::Vector2f scale) {
	this->scale = scale;
	if (!font.loadFromFile("Font/DisposableDroidBB.ttf")) {
		std::cout << "font loading error" << std::endl;
	}
	loadMenu();
}

void SoundMenu::loadMenu() {
	std::string takeFromDocs;

	std::ifstream options("Menu (EN)/Settings/Sound/musicVolume.txt");
	if (!options.is_open()) {
		std::cout << "Menu file cannot open" << filename << std::endl;
		return;
	}

	getline(options, takeFromDocs);
	options.close();
	full = std::count(takeFromDocs.begin(), takeFromDocs.end(), '#');
	empty = 10 - full;
	volume = 10 * full;

	sound.setFillColor(sf::Color(237,28,36));
	not_sound.setFillColor(sf::Color(0, 0, 0));

	sound.setScale(scale);
	not_sound.setScale(scale);

	updatePositionAndSize();

	sf::RectangleShape newButton;
	newButton.setFillColor(sf::Color(255, 157, 10));
	newButton.setOutlineColor(sf::Color(100, 100, 100));
	newButton.setOutlineThickness(4);
	newButton.setSize(sf::Vector2f(400, 44));
	newButton.setScale(scale);
	newButton.setPosition(sf::Vector2f(200 * scale.x, 300 * scale.y));
	buttons.push_back(newButton);

	newButton.setSize(sf::Vector2f(150, 44));
	for (int i = 0; i < 2; i++) {
		newButton.setPosition(sf::Vector2f((200+i*250) * scale.x, scale.y * 376));
		buttons.push_back(newButton);
	}


	sf::Text newText;
	newText.setFillColor(sf::Color::White);
	newText.setScale(scale);
	newText.setFont(font);
	newText.setString("<-");
	newText.setPosition(sf::Vector2f(263 * scale.x, 376 * scale.y));
	menues.push_back(newText);
	newText.setString("->");
	newText.setPosition(sf::Vector2f(513 * scale.x,  376 * scale.y));
	menues.push_back(newText);
}

void SoundMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < buttons.size(); i++)
		window.draw(buttons[i]);
	for (int i = 0; i < menues.size(); i++)
		window.draw(menues[i]);
	window.draw(sound);
	window.draw(not_sound);
}

void SoundMenu::increaseSound() {
	if (full + 1 > 10)
		return;
	full++;
	volume += 10;
	empty--;

	updateBar();
	updatePositionAndSize();
}

void SoundMenu::decreaseSound() {
	if (full -1 < 0)
		return;
	full--;
	volume -= 10;
	empty++;

	updateBar();
	updatePositionAndSize();
}

int SoundMenu::getVolume() {
	return volume;
}
