#pragma once
#include "SDL.h"
class GameObject;

class InputComponent {
public:
	virtual ~InputComponent() {}
	virtual void handleEvents(GameObject& obj, SDL_Event& e) = 0;
};

class BirdInputComponent : public InputComponent {
public:
	virtual void handleEvents(GameObject& obj, SDL_Event& e) override;
};

class PipeInputComponent : public InputComponent {
public:
	virtual void handleEvents(GameObject& , SDL_Event& ) override {};
};