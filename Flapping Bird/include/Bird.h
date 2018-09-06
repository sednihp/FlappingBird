#pragma once
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"

class Bird : public GameObject {
	private:
		const double GRAVITY{ 20 };
		const int WIDTH{ 38 };
		const int HEIGHT{ 24 };
		bool alive{ true };

	public:
		Bird();
		~Bird();

		virtual const SDL_Rect& getBox() override;
		const int getWidth() const { return WIDTH; }
		const int getHeight() const { return HEIGHT; }
		const bool isAlive() const { return alive; }
		void update(const double dt, const int lvlHeight);
		void reset();
};