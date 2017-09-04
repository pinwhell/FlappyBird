#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Game.h"

namespace sermmor {
	class HUD
	{
	public:
		HUD();
		HUD(GameDataRef data);
		void init(GameDataRef data);

		void draw();
		void updateScore(int score);

		~HUD();
	private:
		GameDataRef data;
		sf::Text scoreText;
	};
}


