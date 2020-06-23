#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Text.h"
#include <queue>


class Dialogue {
	sf::RectangleShape mainBox;

	sf::Texture texture;
	sf::Sprite hero;
	Text TEXT; //words+font

	std::queue<std::string> allReplicas;
	std::queue<std::string> allHeroes;
	sf::Vector2f scale;
	
	sf::SoundBuffer buffer;
	sf::Sound sound;
	
	bool toSwitch;
	bool loaded;
	int initialPositionString;

	int timerMS;
	int delayMS;
public:
	Dialogue(sf::Vector2f scale);
	bool loadDialogue(std::string filename);
	void updateScale(sf::Vector2f scale);
	void updateDialogue();
	void changeToSwitch();
	bool getToSwitch();
	void draw(sf::RenderWindow& window);
	bool isReplicaEmpty();
};

