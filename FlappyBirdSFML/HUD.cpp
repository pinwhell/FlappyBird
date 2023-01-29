#include "stdafx.h"
#include "HUD.h"

namespace sermmor {

	HUD::HUD() { }

	HUD::HUD(GameDataRef data) : data(data)
	{
		init(data);
	}

	void HUD::init(GameDataRef data)
	{
		this->data = data;
		scoreText.setFont(data->assets.getFont(KEY_FONT_FLAPPY));
		scoreText.setString("0");
		scoreText.setCharacterSize(90);
		scoreText.setFillColor(sf::Color(255, 255, 255, 255));
		scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height /2);
		scoreText.setPosition(data->window.getSize().x / 2, data->window.getSize().y / 5);
	}

	void HUD::draw()
	{
		data->window.draw(scoreText);
	}

	void HUD::updateScore(int score)
	{
		scoreText.setString(std::to_string(score));
	}


	HUD::~HUD()
	{
	}

}

