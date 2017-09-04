#pragma once

#include <SFML\Graphics.hpp>
#include "Game.h"

namespace sermmor
{
	class Flash {
	public:
		Flash();
		Flash(GameDataRef data);
		void init(GameDataRef data);

		void show(float dt);
		void draw();

		~Flash();

	private:
		GameDataRef data;
		sf::RectangleShape shape;

		bool isFlashOn;
	};
}


