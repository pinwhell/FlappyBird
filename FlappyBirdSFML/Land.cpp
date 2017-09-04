#include "stdafx.h"
#include "Land.h"

namespace sermmor
{
	Land::Land() { }
	Land::Land(GameDataRef data)
	{
		init(data);
	}

	void Land::init(GameDataRef data)
	{
		this->data = data;

		sf::Sprite sprite(data->assets.getTexture(KEY_TEX_LAND));
		sf::Sprite spriteForward(data->assets.getTexture(KEY_TEX_LAND));

		sprite.setPosition(0, data->window.getSize().y - sprite.getGlobalBounds().height);
		spriteForward.setPosition(sprite.getGlobalBounds().width,
			data->window.getSize().y - sprite.getGlobalBounds().height);

		landSprites.push_back(sprite);
		landSprites.push_back(spriteForward);
	}

	void Land::moveLand(float dt)
	{
		float movement;
		for (unsigned short int i = 0; i < landSprites.size(); i++)
		{
			sf::Sprite &currentSprite = landSprites.at(i);
			movement = PIPE_MOVEMENT_SPEED * dt;
			currentSprite.move(-movement, 0.0f);
			
			if (currentSprite.getPosition().x + currentSprite.getGlobalBounds().width < 0)
			{
				// Put forward.
				sf::Vector2f position(data->window.getSize().x, currentSprite.getPosition().y);
				currentSprite.setPosition(position);
			}
		}
	}

	void Land::drawLand()
	{
		for (unsigned short int i = 0; i < landSprites.size(); i++)
		{
			data->window.draw(landSprites.at(i));
		}
	}

	const std::vector<sf::Sprite>& Land::getSprites() const
	{
		return landSprites;
	}

	Land::~Land()
	{
	}
}