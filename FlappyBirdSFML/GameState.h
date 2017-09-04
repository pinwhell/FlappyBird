#pragma once
#include "State.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Game.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"
#include "GameOverState.h"

namespace sermmor {
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

		~GameState();

	private:
		GameDataRef data;
		sf::Sprite spriteBackground;
		Pipe pipe;
		Land land;
		Bird bird;
		Collision collision;
		Flash flash;
		HUD hud;

		sf::SoundBuffer hitSoundBuffer;
		sf::SoundBuffer wingSoundBuffer;
		sf::SoundBuffer pointSoundBuffer;
		sf::Sound hitSound;
		sf::Sound wingSound;
		sf::Sound pointSound;

		sf::Clock clock;
		int gameState;
		int score;

		void initSounds();
		void updatePipes(float dt);
		void updateCollisions(float dt);
		void updateScore(float dt);
	};

}


