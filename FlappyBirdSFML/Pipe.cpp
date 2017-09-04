#include "stdafx.h"
#include "Pipe.h"

namespace sermmor {

	Pipe::Pipe() {}

	Pipe::Pipe(GameDataRef data): data(data)
	{
		init(data);
	}

	Pipe::Pipe(const Pipe & p)
	{
		init(p.data);
	}

	void Pipe::init(GameDataRef data)
	{
		this->data = data;
		createPools();

		landHeight = data->assets.getTexture(KEY_TEX_LAND).getSize().y;
		pipeSpawnYOffset = 0;
	}
	
	void Pipe::createTopPool()
	{
		unsigned int xOutOfScreen = 2 * data->window.getSize().x;

		for (PipePoolInfo pipe : pipeTopPool)
		{
			// Create sprite and put out of screen.
			sf::Sprite sprite(data->assets.getTexture(KEY_TEX_PIPE_UP));
			sprite.setPosition(xOutOfScreen,
				data->window.getSize().y - sprite.getGlobalBounds().height);

			pipe.spritePipe = sprite;
			pipe.type = TOP;
			pipe.isActive = false;
			pipe.wasDefeated = true;
		}
	}
	void Pipe::createDownPool() 
	{
		unsigned int xOutOfScreen = 2 * data->window.getSize().x;

		for (PipePoolInfo pipe : pipeDownPool)
		{
			// Create sprite and put out of screen.
			sf::Sprite sprite(data->assets.getTexture(KEY_TEX_PIPE_DOWN));
			sprite.setPosition(xOutOfScreen, 0);

			pipe.spritePipe = sprite;
			pipe.type =	DOWN;
			pipe.isActive = false;
			pipe.wasDefeated = true;
		}
	}
	void Pipe::createInvisiblePool()
	{
		unsigned int xOutOfScreen = 2 * data->window.getSize().x;

		for (PipePoolInfo pipe : pipeInvisiblePool)
		{
			// Create sprite and put out of screen.
			sf::Sprite sprite(data->assets.getTexture(KEY_TEX_PIPE_UP));
			sprite.setPosition(xOutOfScreen,
				data->window.getSize().y - sprite.getGlobalBounds().height);

			sprite.setColor(sf::Color(0, 0, 0, 0));

			pipe.spritePipe = sprite;
			pipe.type = INVISIBLE;
			pipe.isActive = false;
			pipe.wasDefeated = true;
		}
	}

	void Pipe::createPools()
	{
		createTopPool();
		createDownPool();
		createInvisiblePool();
	}

	Pipe & Pipe::operator=(const Pipe & pOther)
	{
		if (&pOther == this)
			return *this;

		if (&(pOther.pipeSpritesPool) != &(this->pipeSpritesPool))
		{
			pipeSpritesPool.clear();
			std::vector<PipePoolInfo> vStructTemp(pOther.pipeSpritesPool);
			pipeSpritesPool = vStructTemp;

			std::copy(pOther.pipeTopPool, std::end(pOther.pipeTopPool), pipeTopPool);
			std::copy(pOther.pipeDownPool, std::end(pOther.pipeDownPool), pipeDownPool);
			std::copy(pOther.pipeInvisiblePool, std::end(pOther.pipeInvisiblePool), pipeInvisiblePool);
		}

		this->data = pOther.data;

		return *this;
	}

	void Pipe::spawnBottonPipe()
	{
		// Search and take a object not active of the pool.
		PipePoolInfo pipeFree;
		for (PipePoolInfo pipe : pipeDownPool)
		{
			if (!pipe.isActive)
			{
				pipe.isActive = true;
				pipeFree.isActive = true;
				pipeFree.wasDefeated = false;
				pipeFree.spritePipe = pipe.spritePipe;
				pipeFree.spritePipe.setTexture(data->assets.getTexture(KEY_TEX_PIPE_UP));
				pipeFree.type = pipe.type;
			}
		}

		// Put new position & assigne to vector.
		pipeFree.spritePipe.setPosition(data->window.getSize().x,
			data->window.getSize().y - pipeFree.spritePipe.getGlobalBounds().height - pipeSpawnYOffset);

		pipeSpritesPool.push_back(pipeFree);
	}

	void Pipe::spawnTopPipe()
	{
		// Search and take a object not active of the pool.
		PipePoolInfo pipeFree;
		for (PipePoolInfo pipe : pipeTopPool)
		{
			if (!pipe.isActive)
			{
				pipe.isActive = true;
				pipeFree.isActive = true;
				pipeFree.wasDefeated = false;
				pipeFree.spritePipe = pipe.spritePipe;
				pipeFree.spritePipe.setTexture(data->assets.getTexture(KEY_TEX_PIPE_DOWN));
				pipeFree.type = pipe.type;
			}
		}

		// Put new position & assigne to vector.
		pipeFree.spritePipe.setPosition(data->window.getSize().x, -pipeSpawnYOffset);

		pipeSpritesPool.push_back(pipeFree);
	}

	void Pipe::spawnInvisiblePipe()
	{
		// Search and take a object not active of the pool.
		PipePoolInfo pipeFree;
		for (PipePoolInfo pipe : pipeInvisiblePool)
		{
			if (!pipe.isActive)
			{
				pipe.isActive = true;
				pipeFree.isActive = true;
				pipeFree.wasDefeated = false;
				pipeFree.spritePipe = pipe.spritePipe;
				pipeFree.spritePipe.setTexture(data->assets.getTexture(KEY_TEX_PIPE_UP));
				pipeFree.type = pipe.type;
			}
		}

		// Put new position & assigne to vector.
		pipeFree.spritePipe.setPosition(data->window.getSize().x, 
			data->window.getSize().y - pipeFree.spritePipe.getGlobalBounds().height);
		
		pipeFree.spritePipe.setColor(sf::Color(0, 0, 0, 0));

		pipeSpritesPool.push_back(pipeFree);
	}

	bool Pipe::isPipeOnScreen(sf::Sprite &spritePipe)
	{
		return spritePipe.getPosition().x + spritePipe.getGlobalBounds().width >= 0;
	}

	bool Pipe::clearPipesOutScreen(int indexPipe)
	{
		PipePoolInfo &currentPipe = pipeSpritesPool.at(indexPipe);

		bool isPipeOnScreen = this->isPipeOnScreen(currentPipe.spritePipe);

		if (!isPipeOnScreen)
		{
			TypePipe type = currentPipe.type;

			switch (type)
			{
			case sermmor::TOP:
				for (PipePoolInfo pipe : pipeTopPool)
					if (pipe.isActive && this->isPipeOnScreen(pipe.spritePipe))
					{
						pipe.isActive = false;
						pipe.wasDefeated = true;
					}
				break;
			case sermmor::DOWN:
				for (PipePoolInfo pipe : pipeDownPool)
					if (pipe.isActive && this->isPipeOnScreen(pipe.spritePipe))
					{
						pipe.isActive = false;
						pipe.wasDefeated = true;
					}
				break;
			case sermmor::INVISIBLE:
				for (PipePoolInfo pipe : pipeInvisiblePool)
					if (pipe.isActive && this->isPipeOnScreen(pipe.spritePipe))
					{
						pipe.isActive = false;
						pipe.wasDefeated = true;
					}
				break;
			default:
				break;
			}

			currentPipe.isActive = false;
			currentPipe.wasDefeated = true;
			pipeSpritesPool.erase(pipeSpritesPool.begin() + indexPipe);
		}

		return !isPipeOnScreen;

	}

	void Pipe::movePipes(float dt)
	{
		float movement;
		bool isDeleted;
		for (unsigned short int i = 0; i < pipeSpritesPool.size(); i++)
		{
			isDeleted = clearPipesOutScreen(i);

			if (!isDeleted)
			{
				movement = PIPE_MOVEMENT_SPEED * dt;
				pipeSpritesPool.at(i).spritePipe.move(-movement, 0);
			}
		}
	}

	void Pipe::drawPipes()
	{
		for (unsigned short int i = 0; i < pipeSpritesPool.size(); i++)
		{
			PipePoolInfo &currentPipe = pipeSpritesPool.at(i);
			if (currentPipe.isActive)
				data->window.draw(currentPipe.spritePipe);
		}
	}

	void Pipe::RandomisePipeOffset()
	{
		pipeSpawnYOffset = rand() % (landHeight + 1);
	}

	const std::vector<PipePoolInfo>& Pipe::GetSprites() const
	{
		return pipeSpritesPool;
	}

	bool Pipe::checkDefeated(float birdPositionX, float birdWidth)
	{
		bool isIncrementScore = false;

		for (int i = 0; i < pipeSpritesPool.size(); i++)
		{
			PipePoolInfo & pipeInfo = pipeSpritesPool.at(i);
			if (pipeInfo.isActive && !pipeInfo.wasDefeated
				&& pipeInfo.isDefeated(birdPositionX, birdWidth))
			{
				if (!isIncrementScore)
				{
					isIncrementScore = true;
				}
				pipeInfo.wasDefeated = true;
			}
		}

		return isIncrementScore;
	}

	Pipe::~Pipe()
	{
		pipeSpritesPool.clear();
	}
}
