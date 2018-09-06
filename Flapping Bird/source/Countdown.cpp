#include "Countdown.h"
#include "Game.h"
#include "Engine.h"

Countdown::Countdown(MediaCache& mc, Player &p) : State(mc, p),
													countdownTimer(std::make_unique<Timer>()),
													largeFont(mediaCache.getFont(40)), 
													smallFont(mediaCache.getFont(20))
			{
	timerTex = mediaCache.getText(count, largeFont);
	timerTex->setPosition(mediaCache.centreX(timerTex), mediaCache.centreY(timerTex));

	controlsTex = mediaCache.getText("Press space to flap your wings", smallFont);
	controlsTex->setPosition(mediaCache.centreX(controlsTex), mediaCache.centreY(controlsTex) + 2 * controlsTex->getH());
}

Countdown::~Countdown()
{

}

void Countdown::enter(Engine*)
{
	countdownTimer->start();
}

void Countdown::handleEvents(SDL_Event& , Engine* )
{

}

void Countdown::update(const double, Engine* engine)
{
	if (countdownTimer->getSeconds() >= 1)
	{
		--count;
		timerTex = mediaCache.getText(count, largeFont);
		timerTex->setPosition(mediaCache.centreX(timerTex), mediaCache.centreY(timerTex));
		countdownTimer->restart();

		if (count == 0)
		{
			engine->changeState(std::make_unique<Game>(mediaCache, player));
		}
	}
}

void Countdown::render(const double)
{
	mediaCache.render(timerTex);
	mediaCache.render(controlsTex);
}

void Countdown::exit(Engine*)
{

}