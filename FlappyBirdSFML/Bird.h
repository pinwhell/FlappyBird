#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include"Game.h"

namespace sermmor {
	enum BirdState {STILL = 1, FALLING, FLYING};

	class Bird {
	public:
		Bird();
		Bird(GameDataRef data);
		void init(GameDataRef data);

		void draw();
		void animate(float dt);
		void update(float dt);
		void tap();

		const sf::Sprite &getSprite() const;

		~Bird();
	private:
		GameDataRef data;
		sf::Sprite birdSprite;
		sf::Texture animationFrames[BIRD_TOTAL_FRAMES];
		unsigned int currentAnimation;
		
		sf::Clock animationClock;
		sf::Clock movementClock;
		BirdState birdState;
		float rotation;
	};

}
