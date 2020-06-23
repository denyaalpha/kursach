#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Collision.h"
#include "Platform.h"
#include "PersonClass/MainHero.h"

class Map {
	std::vector<sf::Sprite> groundTile; //ground tile - tile, where person can walk
	std::vector<sf::Sprite> miscellaneousTile; //i.e. flowers, grass,...
	std::vector<Platform> collisionTile; //collided tile
	std::string filename; //filename, from where we get all tiles
	sf::Image map_image; //map image - tileset
	sf::Texture map;
	sf::Sprite s_map;

public:
	Map();
	void createMap(const std::string& filename, const std::string& tilename); //loads all tiles
	void loadMap(sf::RenderWindow& window);
	bool checkCollision(Collision &player, float time);
};

