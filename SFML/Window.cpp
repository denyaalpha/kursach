#include "Window.h"

Window::Window(int width, int height, const std::string &title) {
	this->width = width;
	this->height = height;
	this->title = title;
	scale.x = scale.y = 1; //scale. When we change a resolution, everything needs to be scaled
	window.create(sf::VideoMode(width, height), title); //method from SFML
	isOpen = true;
	isFullscreen = false;
	firstB.loadFromFile("Background/Teil1.png"); //Background for menu (for first time we'll be in menu)
	background.setTexture(firstB);
}

bool Window::IsOpen() {
	return isOpen;
}

bool Window::IsFullscreen() {
	return isFullscreen;
}

void Window::clear() {
	window.clear();
}

void Window::draw(sf::Drawable& object) {
	window.draw(object);
}

void Window::draw(Menu *menu) {
	menu->draw(window);
}

void Window::draw(Map& map) {
	map.loadMap(window);
}

void Window::draw(Dialogue& dialogue) {
	dialogue.draw(window);
}

void Window::draw(Person* person) {
	person->draw(window);
}

void Window::draw(Platform& platform) {
	platform.draw(window);
}

void Window::display() {
	window.display();
}

//(event happens)
bool Window::pollEvent(sf::Event& events) {
	return window.pollEvent(events);
}

void Window::close() {
	window.close();
	isOpen = false;
}

sf::Vector2f Window::getScale() const {
	return scale;
}

void Window::changeFullscreen() {
	//fullscreen switch
	window.close(); //close a window to update window properties
	if (!isFullscreen) {
		scale.x = GetSystemMetrics(SM_CXSCREEN)/float(width); //getSystemMetrics() - returns resolution in current PC for some axe
		scale.y = GetSystemMetrics(SM_CYSCREEN)/float(height);
		window.create(sf::VideoMode(width*scale.x, height*scale.y), title, sf::Style::Fullscreen);
	}
	else {
		window.create(sf::VideoMode(width, height), title);
		scale.x = scale.y = 1;
	}
	background.setScale(scale.x, scale.y);
	isFullscreen = !isFullscreen; //смена булла
}

void Window::setView(sf::View& view) {
	window.setView(view);
}

sf::Vector2f Window::getSize() {
	return sf::Vector2f(width, height);
}

