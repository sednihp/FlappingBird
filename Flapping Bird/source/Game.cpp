#include "Game.h"
#include "Engine.h"
#include "CollisionEngine.h"
#include <algorithm>
#include "Countdown.h"
#include "Score.h"
#include "Engine.h"

Game::Game(MediaCache &mc, Player &p) : State(mc, p),
										smallFont(mediaCache.getFont(20)), 
										bird(std::make_unique<Bird>()),
										pipeTimer(std::make_unique<Timer>()),
										lastPipeY(-288 + rand() % 80 + 20)
{
	bird->setPosition({ mediaCache.centreX(bird->getWidth()), mediaCache.centreY(bird->getHeight()) });
}

Game::~Game()
{
}

void Game::enter(Engine*)
{
	player.reset();
	pipeTimer->start();
}

void Game::handleEvents(SDL_Event& e, Engine* )
{
	bird->handleEvents(e);
}

void Game::update(const double dt, Engine* engine)
{
	bool changedState = false;

	bird->update(dt, mediaCache.getScrHeight());

	if (!bird->isAlive())
	{
		changedState = true;
	}

	auto tp = topPipes.begin();
	while (tp != topPipes.end())
	{
		if (!(*tp)->isOnScreen())
		{
			tp = topPipes.erase(tp);
		}
		else if (CollisionEngine::haveCollided(bird->getBox(), (*tp)->getBox()))
		{
			changedState = true;
			break;
		}
		else if ((*tp)->getPosition().x + (*tp)->getWidth() < bird->getPosition().x && !(*tp)->isScored())
		{
			player.addScore(1);
			(*tp)->setScored();
			(*tp)->update(dt);
			++tp;
		}
		else
		{
			(*tp)->update(dt);
			++tp;
		}
	}

	auto bp = bottomPipes.begin();
	while (bp != bottomPipes.end())
	{
		if (!(*bp)->isOnScreen())
		{
			bp = bottomPipes.erase(bp);
		}
		else if (CollisionEngine::haveCollided(bird->getBox(), (*bp)->getBox()))
		{
			changedState = true;
			break;
		}
		else
		{
			(*bp)->update(dt);
			++bp;
		}
	}

	if (!changedState)
	{
		if (pipeTimer->getSeconds() >= 2)
		{
			int y = std::max(-288 + 10, std::min(lastPipeY + rand() % 40 - 20, -90));
			bottomPipes.push_back(std::make_unique<Pipe>(mediaCache.getScrWidth(), y));
			topPipes.push_back(std::make_unique<Pipe>(mediaCache.getScrWidth(), y, true));
			pipeTimer->restart();
		}
	}
	else
	{
		engine->changeState(std::make_unique<Score>(mediaCache, player));
	}
}

void Game::render(const double dt)
{
		bird->render(mediaCache, dt);

		for (const auto& p : topPipes)
		{
			p->render(mediaCache, dt);
		}

		for (const auto& bp : bottomPipes)
		{
			bp->render(mediaCache, dt);
		}

		scoreTex = mediaCache.getText("Score: " + std::to_string(player.getScore()), smallFont);
		scoreTex->setPosition(0, 0);
		mediaCache.render(scoreTex, scoreTex->getPosition());
}

void Game::exit(Engine* )
{

}



void Game::keyPressed(SDL_Event& e, Engine* engine)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RETURN:
			engine->changeState(std::make_unique<Countdown>(mediaCache, player));
			break;
		default:
			break;
		}
	}
}