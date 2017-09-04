#include "stdafx.h"
#include "MainMenuState.h"

namespace sermmor {
	
	MainMenuState::MainMenuState(GameDataRef data) : data(data) { }

	void MainMenuState::init()
	{
		data->assets.loadTexture(KEY_TEX_MAIN_MENU_BACKGROUND, MAIN_MENU_BACKGROUND_FILEPATH);
		data->assets.loadTexture(KEY_TEX_GAME_TITLE, GAME_TITLE_FILEPATH);
		data->assets.loadTexture(KEY_TEX_PLAY_BUTTON, PLAY_BUTTON_FILEPATH);

		spriteBackground.setTexture(this->data->assets.getTexture(KEY_TEX_MAIN_MENU_BACKGROUND));
		spriteTitle.setTexture(this->data->assets.getTexture(KEY_TEX_GAME_TITLE));
		spritePlayButton.setTexture(this->data->assets.getTexture(KEY_TEX_PLAY_BUTTON));

		spriteTitle.setPosition((SCREEN_WIDTH / 2) - (spriteTitle.getGlobalBounds().width / 2),
			spriteTitle.getGlobalBounds().height / 2);

		spritePlayButton.setPosition((SCREEN_WIDTH / 2) - (spritePlayButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (spritePlayButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::handleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				data->window.close();

			if (data->input.isSpriteClicked(spritePlayButton, sf::Mouse::Left, data->window))
				data->machine.addState(StateRef(new GameState(data)), true);
		}
	}

	void MainMenuState::update(float dt)
	{
		
	}

	void MainMenuState::draw(float dt)
	{
		data->window.clear();

		data->window.draw(spriteBackground);
		data->window.draw(spriteTitle);
		data->window.draw(spritePlayButton);

		data->window.display();
	}

	MainMenuState::~MainMenuState()
	{
	}
}