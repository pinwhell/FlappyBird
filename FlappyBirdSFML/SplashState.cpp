#include "stdafx.h"
#include "SplashState.h"

namespace sermmor {

	SplashState::SplashState(GameDataRef data) : data(data) { }

	void SplashState::init()
	{
		data->assets.loadTexture(KEY_TEX_SPLASH_STATE, SPLASH_SCENE_BACKGROUND_FILEPATH);
		spriteBackground.setTexture(this->data->assets.getTexture(KEY_TEX_SPLASH_STATE));
	}

	void SplashState::handleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
			if (sf::Event::Closed == event.type)
				data->window.close();
	}

	void SplashState::update(float dt)
	{
		if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			data->machine.addState(StateRef(new MainMenuState(data)), true);
		}
	}

	void SplashState::draw(float dt)
	{
		data->window.clear();

		data->window.draw(spriteBackground);
		data->window.display();
	}

	SplashState::~SplashState()
	{
	}

}