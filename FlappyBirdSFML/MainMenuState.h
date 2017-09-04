#pragma once
#include "State.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Game.h"

namespace sermmor {
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

		~MainMenuState();

	private:
		GameDataRef data;

		sf::Sprite spriteBackground;
		sf::Sprite spriteTitle;
		sf::Sprite spritePlayButton;
	};
}
