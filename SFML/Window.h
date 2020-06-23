#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "MenuClass/Menu.h"
#include "Map.h"
#include <Windows.h>
#include "PersonClass/Person.h"
#include "Dialogue.h"


//We could not create class Window, but class RenderWindow in SFML contains few required methods that we want to add

class Window {
	int width; //window width
	int height; //window height
	std::string title; //window title
	sf::Texture firstB; //texture with purpose to display background
	sf::RenderWindow window; //window will all properties above
	
	sf::Vector2f scale; //Масштаб (коеф)
	bool isOpen; //state, whether window is open
	bool isFullscreen; //state, whether the window is fullscreen

public:
	sf::Sprite background; //background
	Window(int width, int height, const std::string &title); //Window initiliazation
	bool IsOpen();
	bool IsFullscreen();
	void clear(); //clear
	void draw(sf:: Drawable &object); //display an object
	void draw(Menu *menu); //display a menu
	void draw(Map& map); //display a map
	void draw(Dialogue& dialogue); //display a dialogue
	void draw(Person* person); //display a person
	void draw(Platform& platform); //display a platform
	void display(); //отображение прорисованных спрайтов
	bool pollEvent(sf::Event &events); //сканирует эвенты (нажатия и чет типа такого)
	void close();
	sf::Vector2f getScale() const; //возращает масштаб окна
	void changeFullscreen();
	void setView(sf::View& view);
	sf::Vector2f getSize();
};

