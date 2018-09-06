#pragma once
#include "State.h"
#include "Player.h"
#include "Timer.h"

class Countdown : public State
{
private:
	TTF_Font* largeFont;
	TTF_Font* smallFont;
	GameTex timerTex, controlsTex;
	int count{ 3 };
	double timer{ 0 };
	std::unique_ptr<Timer> countdownTimer;

public:
	Countdown(MediaCache &mc, Player &p);
	~Countdown();

	virtual void enter(Engine* engine) override;
	virtual void handleEvents(SDL_Event& e, Engine* engine) override;
	virtual void update(const double dt, Engine* engine) override;
	virtual void render(const double dt) override;
	virtual void exit(Engine* engine) override;
};
