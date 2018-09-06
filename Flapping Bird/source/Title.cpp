#include "Title.h"
#include "Countdown.h"
#include "Engine.h"

Title::Title(MediaCache &mc, Player &p) : State(mc, p),
											smallFont(mediaCache.getFont(20)),
											largeFont(mediaCache.getFont(40))
{
	generateTextures();
}

Title::~Title()
{

}

void Title::enter(Engine* )
{

}
 
void Title::handleEvents(SDL_Event& e, Engine* engine)
{
	keyPressed(e, engine);
}

void Title::update(const double , Engine* )
{

}

void Title::render(const double )
{
	mediaCache.render(titleTex);
	mediaCache.render(pressEnterTex);
	
}

void Title::exit(Engine* )
{

}

void Title::generateTextures()
{
	titleTex = mediaCache.getText("Flappy Bird", largeFont);
	titleTex->setPosition(mediaCache.centreX(titleTex), mediaCache.centreY(titleTex) - titleTex->getH());

	pressEnterTex = mediaCache.getText("Press enter", smallFont);
	pressEnterTex->setPosition(mediaCache.centreX(pressEnterTex), mediaCache.centreY(pressEnterTex));
}

void Title::keyPressed(SDL_Event& e, Engine* engine)
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