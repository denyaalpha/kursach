#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Window.h"
#include <string>
#include <iostream>
#include "Dialogue.h"
#include "MenuClass/MainMenu.h"
#include "MenuClass/OptionsMenu.h"
#include "MenuClass/SoundMenu.h"
#include "PersonClass/MainHero.h"

enum class StateType { //states of the game (pause, game, main menu etc) 
	MainMenu = 1, Options, Sound, Preambula, Game, Paused
};

class Game {
	Window screen;
	Menu *_menu;
	StateType state;
	Map map;
	Dialogue dialogue;
	sf::Clock clock;
	sf::Time time;
	sf::Music backgroundMusic;
	MainHero person;
	sf::View camera;

public:
	Game();
	void render(); //updates all datas and takes all event
	void update(); //clears and shows screen
	bool isOpen(); //checks is window open or not

	//render all stuff 
	void renderMainMenu(); 
	void renderOptions();
	void renderMenuSound();
	void renderPreambula();
	void renderGame();

	//update all stuff 
	void updateMainMenu();
	void updateOptions();
	void updateMenuSound();
	void updatePreambula();
	void updateGame();
};