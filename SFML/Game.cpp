#include "Game.h"

// window creation
Game::Game() : screen(800, 600, "Devian"), dialogue(screen.getScale()), person() {
	camera.reset(sf::FloatRect(0, 0, 800, 600)); //spawn camera on coordinates
	_menu = new MainMenu(screen.getScale());
	state = StateType::MainMenu;
	backgroundMusic.openFromFile("Music/Terraria - Overworld.wav"); //backgrond music
	backgroundMusic.setLoop(true); //makes music restart after the end
	backgroundMusic.play(); //play

	std::string volume; //volume :)
	std::ifstream takeVolume("Menu (EN)/Settings/Sound/musicVolume.txt");
	takeVolume >> volume;
	takeVolume.close();
	int intVol = std::count(volume.begin(), volume.end(), '#');
	backgroundMusic.setVolume(intVol*10);
}

//render window depend on state of the game
void Game::render() {
	switch (state) {
	case StateType::MainMenu:
		renderMainMenu();
		break;
	case StateType::Options:
		renderOptions();
		break;
	case StateType::Sound:
		renderMenuSound();
		break;
	case StateType::Preambula:
		renderPreambula();
		break;
	case StateType::Game:
		renderGame();
		break;
	default:
		break;
	}
} 

//update window and draw objects on the screen depending on state
void Game::update() {
	screen.clear(); 


	switch (state) {
	case StateType::MainMenu:
		updateMainMenu();
		break;
	case StateType::Options:
		updateOptions();
		break;
	case StateType::Sound:
		updateMenuSound();
		break;
	case StateType::Preambula:
		updatePreambula();
		break;
	case StateType::Game:
		updateGame();
		break;
	default:
		break;
	}
	screen.display();
}

//checking whether the window is open
bool Game::isOpen() {
	return screen.IsOpen();
}



//                                     ===============RENDER===============
//follow the pressing keys in any states


void Game::renderMainMenu() {
	sf::Event event;
	while (screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			screen.close();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
			_menu->scroolUp();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
			_menu->scroolDown();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
			switch (_menu->getTarget()) {
			case 0:
				state = StateType::Preambula;
				delete _menu;
				dialogue.loadDialogue("Preambula");
				dialogue.updateScale(screen.getScale());
				backgroundMusic.openFromFile("Music/Pixel Beats - Highway to Happiness.wav");
				backgroundMusic.play();
				clock.restart();
				break;
			case 1:
				state = StateType::Options;
				delete _menu;
				_menu = new OptionsMenu(screen.getScale(), screen.IsFullscreen());
				break;
			case 2:
				screen.close();
				break;
			}
		}
	}
}

void Game::renderOptions() {
	sf::Event event;
	while (screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			screen.close();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			state = StateType::MainMenu;
			delete _menu;
			_menu = new MainMenu(screen.getScale());
			break;
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
			_menu->scroolUp();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
			_menu->scroolDown();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
			switch (_menu->getTarget()) {
			case 0: //Fullscreen:
				screen.changeFullscreen();
				delete _menu;
				_menu = new OptionsMenu(screen.getScale(), screen.IsFullscreen());
				dialogue.updateScale(screen.getScale());
				break;
			case 1: //Sound
				state = StateType::Sound;
				delete _menu;
				_menu = new SoundMenu(screen.getScale());
				break;
			case 2:
				break;
			default:
				break;
			}
		}
	}
}

void Game::renderMenuSound() {
	sf::Event event;
	while (screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			screen.close();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
			_menu->decreaseSound();
			backgroundMusic.setVolume(_menu->getVolume());
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
			_menu->increaseSound();
			backgroundMusic.setVolume(_menu->getVolume());
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			state = StateType::Options;
			delete _menu;
			_menu = new OptionsMenu(screen.getScale(), screen.IsFullscreen());
		}
	}
}

void Game::renderPreambula() {
	sf::Event event;
	while (screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			screen.close();
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter) {
			dialogue.changeToSwitch();
			if (dialogue.isReplicaEmpty()) {
				state = StateType::Game;
				map.createMap("MainLocation", "MapTileSet"); //first argument is text file with map (txt), second - Tile set (png)
			}
		}
	}
}

void Game::renderGame() {

	sf::Event event;
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time /= 800;
	while (screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			screen.close();
	}


	Collision playerCollRect = person.getCollider();
	if (!map.checkCollision(playerCollRect, time));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			person.moveUp(time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			person.moveDown(time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			person.moveLeft(time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			person.moveRight(time);
		}

	camera.setCenter(person.getCoordinates());
	person.updateCoords();
	screen.setView(camera);
}



//                                     ===============UPDATE===============
void Game::updateMainMenu() {
	screen.draw(screen.background);
	screen.draw(_menu);
}

void Game::updateOptions() {
	screen.draw(screen.background);
	screen.draw(_menu);
}

void Game::updateMenuSound() {
	screen.draw(screen.background);
	screen.draw(_menu);
}

void Game::updateGame() {
	screen.draw(map);
	screen.draw(&person);
}

void Game::updatePreambula() {
	dialogue.updateDialogue();
	screen.draw(dialogue);
}
