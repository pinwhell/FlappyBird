#pragma once
#include <iostream>
#include <fstream>
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "GameState.h"

namespace sermmor {
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

		~GameOverState();

	private:
		GameDataRef data;
		sf::Sprite spriteBackground;
		sf::Sprite gameOverTitle;
		sf::Sprite gameOverContainer;
		sf::Sprite retryButton;
		sf::Sprite medal;

		sf::Text scoreText;
		sf::Text highScoreText;

		int score;
		int highScore;

		void loadAndSaveNewScore();
		void setMedal();
	};

}
