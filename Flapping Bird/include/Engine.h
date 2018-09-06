#pragma once
#include "MediaCache.h"
#include "StateMachine.h"
#include <memory>
#include "Player.h"

class Engine
{
	private:
		const int BG_SCROLL_SPEED{ 30 };
		const int GROUND_SCROLL_SPEED{ 60 };
		double bgScrollingOffset{ 0 };
		double groundScrollingOffset{ 0 };
		GameTex bgTex, groundTex;
		const double FPS{ 60 };
		const double FRAME_LENGTH{ 1000.0 / FPS };
		bool running{ true };
		double previous, lag;
		MediaCache mediaCache;
		std::unique_ptr<StateMachine> stateMachine;
		Player player;

		void handleEvents();
		void update(const double dt);
		void render(const double dt);

		void updateBackground(const double dt);

	public:
		Engine();
		~Engine();

		void run();
		void stopRunning() { running = false; }
		void changeState(std::unique_ptr<State> newState);
};