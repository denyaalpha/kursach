#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "Game.h"
#include <Windows.h>
#include <conio.h>
#include <queue>

int main() {	
	Game a;
	while (a.isOpen()) {
		a.render();
		a.update();
	}

	return 0;
}