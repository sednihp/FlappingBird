#include "Engine.h"
#include "GameException.h"
#include "Title.h"
#include <time.h>

Engine::Engine() :	previous(SDL_GetTicks()), lag(0.0),
					mediaCache(), player()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	stateMachine = std::make_unique<StateMachine>(this, std::make_unique<Title>(mediaCache, player));

	bgTex = mediaCache.getImage("files/background.jpg");
	groundTex = mediaCache.getImage("files/ground.bmp");
}

Engine::~Engine()
{
}

//the main game loop function
//update the game using a fixed time step (defined by FPS and FRAME_LENGTH)
//only render when the game's clock has caught up with the real world
void Engine::run()
{
	try
	{
		while (running)
		{
			double current = SDL_GetTicks();
			double elapsed = current - previous;
			previous = current;
			lag += elapsed;

			handleEvents();
			if (!running)
				break;

			while (lag >= FRAME_LENGTH)
			{
				update(FRAME_LENGTH / 1000);
				lag -= FRAME_LENGTH;
			}

			render(lag / FRAME_LENGTH);
		}
	}
	catch (GameException e)
	{
		throw e;
	}
}

//handle any events that happen (keyboard, mouse etc) locally first, then pass them down to the currentState
void Engine::handleEvents()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
		{
			running = false;
		}
		//the esc key exits the game
		else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
		{
			stopRunning();
		}

		stateMachine->getCurrentState()->handleEvents(e, this);
	}
}

void Engine::update(const double dt)
{
	updateBackground(dt);

	stateMachine->getCurrentState()->update(dt, this);
}

void Engine::updateBackground(const double dt)
{
	bgScrollingOffset -= BG_SCROLL_SPEED * dt;
	if (bgScrollingOffset < -413)
	{
		bgScrollingOffset = 0;
	}

	groundScrollingOffset -= GROUND_SCROLL_SPEED * dt;
	if (groundScrollingOffset < -mediaCache.getScrWidth())
	{
		groundScrollingOffset = 0;
	}
}

void Engine::render(const double dt)
{
	mediaCache.clearScreen();

	mediaCache.render(bgTex, { bgScrollingOffset, 0.0 });
	mediaCache.render(bgTex, { bgScrollingOffset + bgTex->getW(), 0.0 });
	mediaCache.render(groundTex, { groundScrollingOffset, static_cast<double>(mediaCache.getScrHeight() - groundTex->getH()) });

	stateMachine->getCurrentState()->render(dt);

	mediaCache.updateScreen();
}

void Engine::changeState(std::unique_ptr<State> newState)
{
	stateMachine->changeState(std::move(newState));
}