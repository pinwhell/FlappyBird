#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace sermmor
{
	class Land
	{
	public:
		Land();
		Land(GameDataRef data);
		void Land::init(GameDataRef data);

		void moveLand(float dt);
		void drawLand();

		const std::vector<sf::Sprite> &getSprites() const;

		~Land();
	private:
		GameDataRef data;
		std::vector<sf::Sprite> landSprites;
	};
}

