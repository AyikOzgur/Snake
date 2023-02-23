//============================================================================
// Name        : main.cpp
// Author      : ozgur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "window.hpp"
#include "game.hpp"

using namespace std;

int main() {
	Game game;

	while(!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		sf::sleep(sf::seconds(0.1)); // Sleep for 0.2 seconds.
		game.RestartClock();

	}


return 0;
}
