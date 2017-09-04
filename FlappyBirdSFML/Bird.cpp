#include "stdafx.h"
#include "Bird.h"

namespace sermmor {
	Bird::Bird() { }

	Bird::Bird(GameDataRef data) : data(data)
	{
		init(data);
	}

	void Bird::init(GameDataRef data)
	{
		this->data = data;
		currentAnimation = 0;

		animationFrames[0] = data->assets.getTexture(KEY_TEX_BIRD_FRAME1);
		animationFrames[1] = data->assets.getTexture(KEY_TEX_BIRD_FRAME2);
		animationFrames[2] = data->assets.getTexture(KEY_TEX_BIRD_FRAME3);
		animationFrames[3] = data->assets.getTexture(KEY_TEX_BIRD_FRAME4);
		
		birdSprite.setTexture(animationFrames[currentAnimation]);
		birdSprite.setPosition((data->window.getSize().x / 4) - (birdSprite.getGlobalBounds().width / 2),
			(data->window.getSize().y / 2) - (birdSprite.getGlobalBounds().height / 2));
		birdState = STILL;

		// Setting bird origin.
		sf::Vector2f origin = sf::Vector2f(birdSprite.getGlobalBounds().width / 2,
			birdSprite.getGlobalBounds().height / 2);
		birdSprite.setOrigin(origin);
		rotation = 0;
	}

	void Bird::draw()
	{
		data->window.draw(birdSprite);
	}

	void Bird::animate(float dt)
	{
		if (animationClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / BIRD_TOTAL_FRAMES)
		{
			currentAnimation = (currentAnimation < BIRD_TOTAL_FRAMES - 1) ? currentAnimation + 1 : 0;
				
			birdSprite.setTexture(animationFrames[currentAnimation]);
			animationClock.restart();
		}
	}

	void Bird::update(float dt)
	{
		// Update state.
		switch (birdState) {
		case FALLING:
			birdSprite.move(0, GRAVITY * dt);

			rotation += ROTATION_SPEED * dt;
			if (rotation > 25.0f)
				rotation = 25.0f;
			birdSprite.setRotation(rotation);
			break;
		case FLYING:
			birdSprite.move(0, -FLYING_SPEED * dt);

			rotation -= ROTATION_SPEED * dt;
			if (rotation < -25.0f)
				rotation = -25.0f;
			birdSprite.setRotation(rotation);
			break;
		default:
			break;
		}

		// Check whether finish flying or not.
		if (movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
		{
			movementClock.restart();
			birdState = FALLING;
		}
	}

	void Bird::tap()
	{
		movementClock.restart();
		birdState = FLYING;

	}

	const sf::Sprite & Bird::getSprite() const
	{
		return birdSprite;
	}

	Bird::~Bird()
	{
	}
}
