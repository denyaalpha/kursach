#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(sf::Vector2f scale, bool isFullscreen) {
	this->scale = scale;
	if (!font.loadFromFile("Font/DisposableDroidBB.ttf")) {
		std::cout << "font loading error" << std::endl;
	}
	this->isFullscreen = isFullscreen;
	loadMenu();
}

void OptionsMenu::loadMenu() {
	count = 0;
	target = 0;
	menues.clear();
	std::string takeFromDocs;

	std::ifstream marginForText("Menu (EN)/Settings/OptionsMargin.txt");
	if (!marginForText.is_open()) {
		std::cout << "Margin_menu file cannot open" << std::endl;
		return;
	}
	std::vector<int> margins;
	while (!marginForText.eof()) {
		marginForText >> takeFromDocs;
		margins.push_back(std::stoi(takeFromDocs));
	}
	marginForText.close();


	std::ifstream options("Menu (EN)/Settings/Options.txt");//reading txt file menu
	if (!options.is_open()) {
		std::cout << "cannot open a file " << filename << std::endl;
		return;
	}

	sf::RectangleShape newButton;
	newButton.setFillColor(sf::Color(255, 157, 10));
	newButton.setOutlineThickness(4);
	newButton.setOutlineColor(sf::Color(100, 100, 100));
	newButton.setSize(sf::Vector2f(400, 44));
	newButton.setScale(scale);

	std::vector<std::string> newMenuBar;
	while (!options.eof()) {
		getline(options, takeFromDocs);
		newMenuBar.push_back(takeFromDocs);
		count++;
	}

	sf::Text newText;
	newText.setFillColor(sf::Color::White);
	newText.setFont(font);
	newText.setScale(scale);

	if (isFullscreen)
		newMenuBar[0] += " On";
	else
		newMenuBar[0] += " Off";

	newText.setString(newMenuBar[0]);
	newText.setPosition(sf::Vector2f((margins[isFullscreen] + 200) * scale.x, scale.y * 300));
	newButton.setPosition(sf::Vector2f(200 * scale.x, scale.y * 300));
	buttons.push_back(newButton);
	menues.push_back(newText);


	for (int i = 1; i < count; i++) {
		newText.setString(newMenuBar[i]);
		newText.setPosition(sf::Vector2f((margins[i+1] + 200) *scale.x, scale.y*(300 + 44 * i + 32 * i)));
		newButton.setPosition(sf::Vector2f(200*scale.x, scale.y*(300 + 44 * i + 32 * i)));
		buttons.push_back(newButton);
		menues.push_back(newText);
	}

	menues[target].setFillColor(sf::Color::Red);
	options.close();
}