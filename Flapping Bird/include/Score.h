#pragma once
#include "State.h"

class Score : public State {
private:
	TTF_Font * largeFont;
	TTF_Font* smallFont;
	GameTex youLostTex, scoreTex, playAgainTex, highScoreTex;
	bool highScore = false;

	void keyPressed(SDL_Event& e, Engine* engine);
	void generateTextures();

public:
	Score(MediaCache &mc, Player &p);
	~Score();

	virtual void enter(Engine* engine) override;
	virtual void handleEvents(SDL_Event& e, Engine* engine) override;
	virtual void update(const double dt, Engine* engine) override;
	virtual void render(const double dt) override;
	virtual void exit(Engine* engine) override;
};