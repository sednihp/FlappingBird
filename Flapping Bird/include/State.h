#pragma once
#include "MediaCache.h"
#include <iostream>
#include "Player.h"
class Engine;

class State
{
	private:
		State & operator=(const State&) = delete;
		State(const State&) = delete;

	protected:
		MediaCache &mediaCache;
		Player& player;

	public:
		State(MediaCache &mc, Player &p) : mediaCache(mc), player(p) {}
		virtual ~State() {};

        virtual void enter(Engine* engine) = 0;
		virtual void handleEvents(SDL_Event& e, Engine* engine) = 0;
		virtual void update(const double dt, Engine* engine) = 0;
		virtual void render(const double dt) = 0;
		virtual void exit(Engine* engine) = 0;
};