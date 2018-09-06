#pragma once
#include "State.h"
#include "Player.h"

class Title : public State
{
private:
	TTF_Font* largeFont;
	TTF_Font* smallFont;
	GameTex titleTex, pressEnterTex;

	void generateTextures();
	void keyPressed(SDL_Event& e, Engine* engine);

public:
	Title(MediaCache &mc, Player &p);
	~Title();

	virtual void enter(Engine* engine) override;
	virtual void handleEvents(SDL_Event& e, Engine* engine) override;
	virtual void update(const double dt, Engine* engine) override;
	virtual void render(const double dt) override;
	virtual void exit(Engine* engine) override;
};
