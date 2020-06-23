#include "Map.h"

Map::Map() {
}

void Map::createMap(const std::string& filename, const std::string &tilename) {
	map_image.loadFromFile("Images/TileMap/" + tilename + ".png"); //load our tileset
	map.loadFromImage(map_image);

	std::ifstream loader("Maps/Ground/" + filename + ".txt");
	if (!loader.is_open()) {
		std::cout << "Map file cannot open groundTile " << filename << std::endl;
		return;
	}
	std::ifstream loaderCollision("Maps/Collision/" + filename+ ".txt");
	if (!loaderCollision.is_open()) {
		std::cout << "Map file cannot open collisionTile " << filename << std::endl;
		return;
	}

	std::ifstream loaderMisc("Maps/Miscellaneous/" + filename + ".txt");
	if (!loaderCollision.is_open()) {
		std::cout << "Map file cannot open miscTile " << filename << std::endl;
		return;
	}

	/*
	Basic priciples of loading a map:
	Each map consist of 3 types of tiles: collided, ground, miscellaneous (they will be loaded from .txt file)
	Each map contains numbers, which represents which tile from tileset will be taken. All loaded tiles will be
	stored in vector. The reason is because we need don't want to load our map each time
	*/

	std::string take, take2, take3;
	int iterator_x = 0, iterator_y = 0;
	sf::Sprite newSprite;
	sf::Vector2f newPosition;
	Platform newPlatform;
	newSprite.setTexture(map);

	while (!loader.eof()) {
		getline(loader, take);
		getline(loaderCollision, take2);
		getline(loaderMisc, take3);
		size_t pos = 0, pos2 = 0, pos3 = 0;

		std::string token, token2;
		std::string delim = ",";
		int numPos;
		iterator_x = 0;
		while ((pos = take.find(delim)) != std::string::npos) {
			token = take.substr(0, pos); //substr will return substring of the object starting at position pos
			take.erase(0, pos + delim.length());
			numPos = stoi(token, nullptr, 10);
			newSprite.setTextureRect(sf::IntRect((numPos % 20 - 1) * 32 + numPos % 20, numPos / 20 * 32 + numPos / 20 + 1, 32, 32));
			newSprite.setPosition(iterator_x * 32, iterator_y * 32);
			groundTile.push_back(newSprite);
			iterator_x++;
		}


		iterator_x = 0;
		while ((pos2 = take2.find(delim)) != std::string::npos) {
			token2 = take2.substr(0, pos2); //substr will return substring of the object starting at position pos
			take2.erase(0, pos2 + delim.length());
			numPos = stoi(token2, nullptr, 10);
			if (numPos != 0) {
				newPosition.x = iterator_x * 32;
				newPosition.y = iterator_y * 32;
				newPlatform.setPlatform(map, 
					sf::IntRect((numPos % 20 - 1) * 32 + numPos % 20, numPos / 20 * 32 + numPos / 20 + 1, 32, 32),
					sf::Vector2f(32,32), 
					newPosition);
				collisionTile.push_back(newPlatform);
			}
			iterator_x++;
		}

		iterator_x = 0;
		while ((pos3 = take3.find(delim)) != std::string::npos) {
			token = take3.substr(0, pos3); //substr will return substring of the object starting at position pos
			take3.erase(0, pos3 + delim.length());
			numPos = stoi(token, nullptr, 10);
			if (numPos) {
				newSprite.setTextureRect(sf::IntRect((numPos % 20 - 1) * 32 + numPos % 20, numPos / 20 * 32 + numPos / 20 + 1, 32, 32));
				newSprite.setPosition(iterator_x * 32, iterator_y * 32);
				miscellaneousTile.push_back(newSprite);
			}
			iterator_x++;
		}
		iterator_y++;
	}

	loader.close();
	loaderCollision.close();
	loaderMisc.close();
}

void Map::loadMap(sf::RenderWindow& window) { //loading map in three layers (ground, objects with collision and without it)
	for (int i = 0; i < groundTile.size(); i++)
		window.draw(groundTile[i]);
	for (int i = 0; i < collisionTile.size(); i++)
		collisionTile[i].draw(window);
	for (int i = 0; i < miscellaneousTile.size(); i++) {
		window.draw(miscellaneousTile[i]);
	}
}

bool Map::checkCollision(Collision& player, float time) { //Check collision of hero with objects
	bool isCollidedOnce = false; //if our hero has collided
	for (int i = 0; i < collisionTile.size(); i++)
		isCollidedOnce += collisionTile[i].getCollider().checkCollision(player, 1.0f, time);
	return isCollidedOnce;
}
