#include "stdafx.h"
#include "GameOverState.h"


namespace sermmor {
	GameOverState::GameOverState(GameDataRef data, int score) : data(data), score(score) {}

	void GameOverState::init()
	{
		loadAndSaveNewScore();

		data->assets.loadTexture(KEY_TEX_GAME_OVER_BACKGROUND, GAME_OVER_BACKGROUND_FILEPATH);
		data->assets.loadTexture(KEY_TEX_GAME_OVER_TITLE, GAME_OVER_TITLE_FILEPATH);
		data->assets.loadTexture(KEY_TEX_GAME_OVER_BODY, GAME_OVER_BODY_FILEPATH);

		spriteBackground.setTexture(this->data->assets.getTexture(KEY_TEX_GAME_OVER_BACKGROUND));
		gameOverContainer.setTexture(this->data->assets.getTexture(KEY_TEX_GAME_OVER_BODY));
		gameOverTitle.setTexture(this->data->assets.getTexture(KEY_TEX_GAME_OVER_TITLE));
		retryButton.setTexture(this->data->assets.getTexture(KEY_TEX_PLAY_BUTTON));

		gameOverContainer.setPosition((data->window.getSize().x / 2) - (gameOverContainer.getGlobalBounds().width / 2),
			(data->window.getSize().y / 2) - (gameOverContainer.getGlobalBounds().height / 2));
		gameOverTitle.setPosition((data->window.getSize().x / 2) - (gameOverTitle.getGlobalBounds().width / 2),
			gameOverContainer.getPosition().y - (gameOverTitle.getGlobalBounds().height * 1.2f));
		retryButton.setPosition((data->window.getSize().x / 2) - (retryButton.getGlobalBounds().width / 2),
			gameOverContainer.getPosition().y + gameOverContainer.getGlobalBounds().height + (retryButton.getGlobalBounds().height * 0.2f));

		scoreText.setFont(data->assets.getFont(KEY_FONT_FLAPPY));
		scoreText.setString(std::to_string(score));
		scoreText.setCharacterSize(37);
		scoreText.setFillColor(sf::Color::White);
		scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
		scoreText.setPosition(data->window.getSize().x / 10 * 7.25, data->window.getSize().y / 2.15);

		highScoreText.setFont(data->assets.getFont(KEY_FONT_FLAPPY));
		highScoreText.setString(std::to_string(highScore));
		highScoreText.setCharacterSize(37);
		highScoreText.setFillColor(sf::Color::White);
		highScoreText.setOrigin(highScoreText.getGlobalBounds().width / 2, highScoreText.getGlobalBounds().height / 2);
		highScoreText.setPosition(data->window.getSize().x / 10 * 7.25, data->window.getSize().y / 1.78);

		setMedal();
	}

	void GameOverState::setMedal()
	{

		if (score >= PLATINUM_MEDAL_SCORE)
		{
			data->assets.loadTexture(KEY_TEX_PLATINUM_MEDAL, PLATINUM_MEDAL_FIREPATH);
			medal.setTexture(data->assets.getTexture(KEY_TEX_PLATINUM_MEDAL));
		}
		else if (score >= GOLD_MEDAL_SCORE)
		{
			data->assets.loadTexture(KEY_TEX_GOLD_MEDAL, GOLD_MEDAL_FIREPATH);
			medal.setTexture(data->assets.getTexture(KEY_TEX_GOLD_MEDAL));
		}
		else if (score >= SILVER_MEDAL_SCORE)
		{
			data->assets.loadTexture(KEY_TEX_SILVER_MEDAL, SILVER_MEDAL_FIREPATH);
			medal.setTexture(data->assets.getTexture(KEY_TEX_SILVER_MEDAL));
		}
		else if (score >= BRONZE_MEDAL_SCORE)
		{
			data->assets.loadTexture(KEY_TEX_BRONZE_MEDAL, BRONZE_MEDAL_FIREPATH);
			medal.setTexture(data->assets.getTexture(KEY_TEX_BRONZE_MEDAL));
		}

		medal.setPosition(103, 272);
	}

	void GameOverState::loadAndSaveNewScore()
	{
		std::ifstream readFile;
		readFile.open(HIGHSCORE_PATH);
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> highScore;
			}
		}
		readFile.close();

		std::ofstream writeFile(HIGHSCORE_PATH);
		if (writeFile.is_open())
		{
			if (score > highScore)
			{
				highScore = score;
			}
			writeFile << highScore;
		}
		writeFile.close();
	}

	void GameOverState::handleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				data->window.close();
			if (data->input.isSpriteClicked(retryButton, sf::Mouse::Left, data->window))
				data->machine.addState(StateRef(new GameState(data)), true);
		}
	}

	void GameOverState::update(float dt)
	{

	}

	void GameOverState::draw(float dt)
	{
		data->window.clear();

		data->window.draw(spriteBackground);
		data->window.draw(gameOverTitle);
		data->window.draw(gameOverContainer);
		data->window.draw(retryButton);
		data->window.draw(scoreText);
		data->window.draw(highScoreText);
		data->window.draw(medal);

		data->window.display();
	}

	GameOverState::~GameOverState()
	{
	}
}