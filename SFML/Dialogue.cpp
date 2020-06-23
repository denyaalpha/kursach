#include "Dialogue.h"

Dialogue::Dialogue(sf::Vector2f scale) {
	this->scale = scale;
	mainBox.setFillColor(sf::Color(100, 100, 100));
	mainBox.setSize(sf::Vector2f(700*scale.x, 100*scale.y));

	TEXT.setFont("DisposableDroidBB");
	TEXT.setColor(sf::Color::White);

	TEXT.setPosition(sf::Vector2f(scale.x * (207 + 10), scale.y * (460 + 10)));
	mainBox.setPosition(sf::Vector2f(50*scale.x, 450*scale.y));
	hero.setPosition(sf::Vector2f(60*scale.x, 460*scale.y));

	toSwitch = true;

	if (!buffer.loadFromFile("SoundEffects/DialogueRunning.wav"))
		std::cout << "No sound:c" << std::endl;
	sound.setBuffer(buffer);
	sound.setVolume(20);
	loaded = false;
}

bool Dialogue::loadDialogue(std::string filename) {
	std::ifstream textDialogue("Dialogs/" + filename + ".txt");
	if (!textDialogue.is_open()) {
		std::cout << "dialogs error\n";
		return false;
	}

	std::string replica;
	std::string numHero;

	allReplicas.push("-");
	while (!textDialogue.eof()) {
		getline(textDialogue,replica);
		getline(textDialogue, numHero);

		allReplicas.push(replica);
		allHeroes.push(numHero);
	}
	loaded = true;
	return true;
}

void Dialogue::updateScale(sf::Vector2f scale) {
	this->scale = scale;
	mainBox.setSize(sf::Vector2f(700 * scale.x, 100 * scale.y));
	mainBox.setPosition(sf::Vector2f(50 * scale.x, 450 * scale.y));
	hero.setPosition(sf::Vector2f(60 * scale.x, 460 * scale.y));
	TEXT.setPosition(sf::Vector2f(scale.x * (207 + 10), scale.y * (460 + 10)));
}

void Dialogue::updateDialogue() {
	if (!toSwitch)
		return;
	if (!loaded)
		return;
	texture.loadFromFile("Dialogs/" + allHeroes.front() +".png");
	hero.setTexture(texture);
	hero.setScale(scale);
	initialPositionString = 0;
	
	allReplicas.pop();
	allHeroes.pop();
	TEXT.clearText();
	toSwitch = false;
	timerMS = 0;
	delayMS = 0;
}

bool Dialogue::getToSwitch() {
	return toSwitch;
}

void Dialogue::draw(sf::RenderWindow& window) {
	if (!loaded)
		return;
	window.draw(mainBox);
	window.draw(hero);
	if (delayMS < 0) {
		delayMS++;
		window.draw(TEXT.getText());
		return;
	}

	if (allReplicas.front()[initialPositionString] == '.')
		delayMS = -2000;
	else
		timerMS++;
	if (initialPositionString < allReplicas.front().length()) {
		if (!(timerMS%100)) {
			TEXT.addLetter(allReplicas.front()[initialPositionString++]);
			sound.play();
		}
	}
	window.draw(TEXT.getText());
}

bool Dialogue::isReplicaEmpty() {
	return (allReplicas.size() == 1);
}

void Dialogue::changeToSwitch() {
	toSwitch = !toSwitch;
}
