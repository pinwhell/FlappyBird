#pragma once

#include <SFML\Graphics.hpp>

namespace sermmor {
	class InputManager {
	public:
		InputManager();
		~InputManager();

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & windows);
		sf::Vector2i getMousePosition(sf::RenderWindow & window);
	};
}

