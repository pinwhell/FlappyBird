#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include<iostream>

namespace sermmor {

	enum TypePipe {TOP = 0, DOWN, INVISIBLE};

	struct PipePoolInfo {
		sf::Sprite spritePipe;
		TypePipe type;
		bool wasDefeated;
		bool isActive;

		bool isDefeated(float positionPlayerX, float widthPlayer)
		{
			if (!wasDefeated)
				wasDefeated = spritePipe.getPosition().x < positionPlayerX;

			return wasDefeated;
		}
	};

	class Pipe {
	public:
		Pipe(GameDataRef data);
		void init(GameDataRef data);

#pragma region Orthodox Canonical Class Form
		Pipe();
		Pipe(const Pipe &p); // Copy constructor.
		Pipe & operator= (const Pipe & pOther);
		~Pipe();
#pragma endregion
		
		void spawnBottonPipe();
		void spawnTopPipe();
		void spawnInvisiblePipe();
		void movePipes(float dt);
		void drawPipes();
		void RandomisePipeOffset();

		const std::vector<PipePoolInfo> &GetSprites() const;
		bool checkDefeated(float birdPositionX, float birdWidth);
		
	private:
		GameDataRef data;
		
		std::vector<PipePoolInfo> pipeSpritesPool;

		PipePoolInfo pipeTopPool [PIPE_SIZE_POOL];
		PipePoolInfo pipeDownPool[PIPE_SIZE_POOL];
		PipePoolInfo pipeInvisiblePool[PIPE_SIZE_POOL];

		int landHeight, pipeSpawnYOffset;

		bool clearPipesOutScreen(int indexPipe);
		void createPools();
		void createTopPool();
		void createDownPool();
		void createInvisiblePool();
		bool isPipeOnScreen(sf::Sprite &spritePipe);
	};
}

