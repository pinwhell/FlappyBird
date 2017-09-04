#include "stdafx.h"
#include "Flash.h"

namespace sermmor
{
	Flash::Flash() { }

	Flash::Flash(GameDataRef data) : data(data)
	{
		init(data);
	}

	void Flash::init(GameDataRef data)
	{
		this->data = data;

		shape = sf::RectangleShape(sf::Vector2f(data->window.getSize()));
		shape.setFillColor(sf::Color(255, 255, 255, 0));
		isFlashOn = true;
	}

	void Flash::show(float dt)
	{
		if (isFlashOn)
		{
			int alpha = (int)shape.getFillColor().a + (FLASH_SPEED * dt);
			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				isFlashOn = false;
			}
			shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)shape.getFillColor().a - (FLASH_SPEED * dt);
			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
				isFlashOn = false;
			}
			shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}

	void Flash::draw()
	{
		data->window.draw(shape);
	}

	Flash::~Flash()
	{
	}
}
