#include "Score.h"
#include "Engine.h"
#include "Countdown.h"

Score::Score(MediaCache &mc, Player &p) : State(mc, p), 
											smallFont(mediaCache.getFont(20)), 
											largeFont(mediaCache.getFont(40))
{
	generateTextures();
}

Score::~Score()
{

}

void Score::enter(Engine* ) 
{
	if (player.updateHighScore())
	{
		highScore = true;
	}
}

void Score::handleEvents(SDL_Event& e, Engine* engine) 
{
	keyPressed(e, engine);
}

void Score::update(const double , Engine* ) 
{
}

void Score::render(const double ) 
{
	mediaCache.render(youLostTex);
	mediaCache.render(scoreTex);

	if (highScore)
	{
		mediaCache.render(highScoreTex);
	}

	mediaCache.render(playAgainTex);
}

void Score::exit(Engine* ) 
{

}

void Score::keyPressed(SDL_Event& e, Engine* engine)
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

void Score::generateTextures()
{
	youLostTex = mediaCache.getText("Oof, you lost", largeFont);
	youLostTex->setPosition(mediaCache.centreX(youLostTex), mediaCache.centreY(youLostTex) - youLostTex->getH());

	scoreTex = mediaCache.getText("Score: " + std::to_string(player.getScore()), smallFont);
	scoreTex->setPosition(mediaCache.centre(scoreTex));

	highScoreTex = mediaCache.getText("New high score", smallFont);
	highScoreTex->setPosition(mediaCache.centreX(highScoreTex), mediaCache.centreY(highScoreTex) + highScoreTex->getH());

	playAgainTex = mediaCache.getText("Press enter to play again", smallFont);
	playAgainTex->setPosition(mediaCache.centreX(playAgainTex->getW()), mediaCache.centreY(playAgainTex->getH()) + playAgainTex->getH() * 2);
}