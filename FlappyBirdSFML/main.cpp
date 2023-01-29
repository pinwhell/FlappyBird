// FlappyBirdSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"

sf::RenderStates const sf::RenderStates::Default;

void HandleEvents(sf::RenderWindow &window);

int main()
{
	sermmor::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "SFML Starter");
	/*sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Awesome SFML");

	while (window.isOpen())
	{
		// Handle events.
		HandleEvents(window);

		// Update game logic.

		// Draw.
		window.clear();

		// Draw SFML objects.

		window.display();
	}*/

    return 0;
}

void HandleEvents(sf::RenderWindow &window)
{
	sf::Event event;

	while (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed: // Si pulsa en cerrar ventana, cerramos la ventana.
			window.close();
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			break;
		}
	}
}

