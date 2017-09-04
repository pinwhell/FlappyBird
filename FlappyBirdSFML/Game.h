#pragma once
#include <memory>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "DEFINITIONS.h"
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace sermmor {

	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);
		~Game();
	private:
		const float dt = 1.0f / 60.0f; // Framerate.
		sf::Clock clock;
		GameDataRef data = std::make_shared<GameData>();

		void run();
	};
}

