#pragma once
#include "State.h"
#include "Bird.h"
#include "Player.h"
#include "Timer.h"
#include "Pipe.h"

class Game : public State
{
	private:
		TTF_Font* smallFont;
		GameTex scoreTex;
		std::unique_ptr<Bird> bird;	
		std::unique_ptr<Timer> pipeTimer;
		std::vector<std::unique_ptr<Pipe>> topPipes;
		std::vector<std::unique_ptr<Pipe>> bottomPipes;
		int lastPipeY;

		void keyPressed(SDL_Event& e, Engine* engine);

	public:
		Game(MediaCache &mc, Player &p);
		~Game();

		virtual void enter(Engine* engine) override;
		virtual void handleEvents(SDL_Event& e, Engine* engine) override;
		virtual void update(const double dt, Engine* engine) override;
		virtual void render(const double dt) override;
		virtual void exit(Engine* engine) override;
};
