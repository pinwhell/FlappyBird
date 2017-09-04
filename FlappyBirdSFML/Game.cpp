#include "stdafx.h"
#include "Game.h"
#include "SplashState.h"

namespace sermmor {

	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL)); // The seed of each random number not based in time.
		data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		data->machine.addState(StateRef(new SplashState(this->data)));
		this->run();
	}

	Game::~Game() { }

	void Game::run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->data->window.isOpen())
		{
			this->data->machine.processStateChanges();

			// TIME REFLESH
			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime; 

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			// Update and Draw States of the game.
			StateRef& activeState = this->data->machine.getActiveState();
			while (accumulator >= dt)
			{
				activeState->handleInput();
				activeState->update(dt);
				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			activeState->draw(interpolation);
		}
	}

}


