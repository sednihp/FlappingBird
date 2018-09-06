#pragma once
#include "GameObject.h"

class Pipe : public GameObject {
private:
	const int HEIGHT{ 288 };
	const int WIDTH{ 70 };
	const int PIPE_SPEED{ 60 };
	const int GAP{ 90 };
	bool onScreen{ true };
	bool scored{ false };

public:
	Pipe(const int scrWidth, const int y, bool pipeFlip = false);
	~Pipe();

	const bool isOnScreen() const { return onScreen; }
	const bool isScored() const { return scored; }
	void setScored() { scored = true; }
	const int getWidth() const { return WIDTH; }
	virtual const SDL_Rect& getBox() override;

	void update(const double dt);
};