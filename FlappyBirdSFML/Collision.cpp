#include "stdafx.h"
#include "Collision.h"

namespace sermmor {

	Collision::Collision()
	{
	}

	bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
	}

	bool Collision::checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
	{
		sprite1.setScale(scale1, scale1);
		sprite2.setScale(scale2, scale2);

		return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
	}

	Collision::~Collision()
	{
	}
}

