#include "stdafx.h"
#include "GameState.h"

namespace sermmor {
	GameState::GameState(GameDataRef data) : data(data)	{}

	void GameState::init()
	{
		initSounds();

		data->assets.loadTexture(KEY_TEX_GAME_BACKGROUND, GAME_BACKGROUND_FILEPATH);
		data->assets.loadTexture(KEY_TEX_PIPE_UP, PIPE_UP_FILEPATH);
		data->assets.loadTexture(KEY_TEX_PIPE_DOWN, PIPE_DOWN_FILEPATH);
		data->assets.loadTexture(KEY_TEX_LAND, LAND_FILEPATH);
		data->assets.loadTexture(KEY_TEX_BIRD_FRAME1, BIRD_FILE_FRAME1_FILEPATH);
		data->assets.loadTexture(KEY_TEX_BIRD_FRAME2, BIRD_FILE_FRAME2_FILEPATH);
		data->assets.loadTexture(KEY_TEX_BIRD_FRAME3, BIRD_FILE_FRAME3_FILEPATH);
		data->assets.loadTexture(KEY_TEX_BIRD_FRAME4, BIRD_FILE_FRAME4_FILEPATH);
		data->assets.loadFont(KEY_FONT_FLAPPY, FLAPPY_FONT_FILEPATH);

		this->pipe.init(data);
		this->land.init(data);
		this->bird.init(data);
		this->flash.init(data);
		this->hud.init(data);

		spriteBackground.setTexture(this->data->assets.getTexture(KEY_TEX_GAME_BACKGROUND));

		score = 0;
		hud.updateScore(score);

		gameState = GameStates::GAME_READY;
	}

	void GameState::initSounds()
	{
		if (!hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
			std::cout << "Error loading Hit sound effect." << std::endl;
		if (!wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
			std::cout << "Error loading Wing sound effect." << std::endl;
		if (!pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
			std::cout << "Error loading Point sound effect." << std::endl;

		hitSound.setBuffer(hitSoundBuffer);
		wingSound.setBuffer(wingSoundBuffer);
		pointSound.setBuffer(pointSoundBuffer);
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				data->window.close();

			if (data->input.isSpriteClicked(spriteBackground, sf::Mouse::Left, data->window))
			{
				if (GameStates::GAME_OVER != gameState && GameStates::GAME_PAUSE != gameState)
				{
					gameState = GameStates::GAME_PLAYING;
					bird.tap();
					wingSound.play();
				}
			}

			if (sf::Event::KeyReleased == event.type && sf::Keyboard::Return == event.key.code)
				if (GameStates::GAME_PLAYING == gameState)
					gameState = GameStates::GAME_PAUSE;
				else if (GameStates::GAME_PAUSE == gameState)
					gameState = GameStates::GAME_PLAYING;
		}
	}

	void GameState::updatePipes(float dt)
	{
		pipe.movePipes(dt);

		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipe.RandomisePipeOffset();

			pipe.spawnInvisiblePipe();
			pipe.spawnBottonPipe();
			pipe.spawnTopPipe();

			clock.restart();
		}
	}

	void GameState::updateCollisions(float dt)
	{
		bool isInGameOver = false;

		std::vector<sf::Sprite> landSprites = land.getSprites();
		for (int i = 0; i < landSprites.size(); i++)
			if (collision.checkSpriteCollision(bird.getSprite(), 0.7f, landSprites.at(i), 1.0f))
			{
				isInGameOver = true;
				break;
			}

		if (!isInGameOver)
		{
			std::vector<PipePoolInfo> pipeSprites = pipe.GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++)
			{
				sf::Sprite & sprite = pipeSprites.at(i).spritePipe;
				if (collision.checkSpriteCollision(bird.getSprite(), 0.625f, sprite, 1.0f))
				{
					isInGameOver = true;
					break;
				}
			}
		}

		if (isInGameOver)
		{
			gameState = GameStates::GAME_OVER;
			clock.restart();
			hitSound.play();
		}
	}

	void GameState::updateScore(float dt)
	{
		float birdPositionX = bird.getSprite().getPosition().x;
		float birdWidth = bird.getSprite().getGlobalBounds().width;

		if (pipe.checkDefeated(birdPositionX, birdWidth))
		{
			score++;
			hud.updateScore(score);
			pointSound.play();
		}
	}

	void GameState::update(float dt)
	{
		if (GameStates::GAME_PAUSE == gameState)
			return;

		if (GameStates::GAME_OVER != gameState)
		{
			land.moveLand(dt);
			bird.animate(dt);
		}
		
		if (GameStates::GAME_PLAYING == gameState)
		{
			updatePipes(dt);
			bird.update(dt);
			updateScore(dt);

			// Checking collisions.
			updateCollisions(dt);
		}

		if (GameStates::GAME_OVER == gameState)
		{
			flash.show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				data->machine.addState(StateRef(new GameOverState(data, score)), true);
			}
		}
	}

	void GameState::draw(float dt)
	{
		data->window.clear();

		data->window.draw(spriteBackground);
		pipe.drawPipes();
		land.drawLand();
		bird.draw();
		flash.draw();
		hud.draw();

		data->window.display();
	}

	GameState::~GameState()
	{
	}
}
