#pragma once
#include "State.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "MainMenuState.h"

namespace sermmor {
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

		~SplashState();

	private:
		GameDataRef data;
		sf::Clock clock;
		sf::Sprite spriteBackground;
	};

}