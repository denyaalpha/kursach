#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f scale) {
	if (!font.loadFromFile("Font/DisposableDroidBB.ttf")) {
		std::cout << "font loading error" << std::endl;
	}
	this->scale = scale;
	loadMenu();
}

void MainMenu::loadMenu() {
	count = 0;
	target = 0;
	menues.clear();
	std::string takeFromDocs;

	//Part of code to check, what the margin of each text menu is
	std::ifstream marginForText("Menu (EN)/MainMenuMargin.txt");
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


	//Text for menu
	std::ifstream options("Menu (EN)/MainMenu.txt");//reading txt file menu
	if (!options.is_open()) {
		std::cout << "Menu file cannot open" << filename << std::endl;
		return;
	}

	sf::Text newText;
	
	newText.setFillColor(sf::Color::White);
	newText.setScale(scale);
	newText.setFont(font);

	sf::RectangleShape newButton;
	newButton.setFillColor(sf::Color(255, 157, 10));
	newButton.setOutlineThickness(4);
	newButton.setOutlineColor(sf::Color(100, 100, 100));
	newButton.setSize(sf::Vector2f(400, 44));
	newButton.setScale(scale);

	while (!options.eof()) {
		getline(options, takeFromDocs);
		newText.setString(takeFromDocs);
		newText.setPosition(sf::Vector2f(scale.x*(200+margins[count]), scale.y*(300 + 44 * count + 32 * count)));
		newButton.setPosition(sf::Vector2f(200*scale.x, scale.y*(300 + 44 * count + 32 * count)));
		menues.push_back(newText);
		count++;
		buttons.push_back(newButton);
	}

	menues[target].setFillColor(sf::Color::Red);
	options.close();
}
