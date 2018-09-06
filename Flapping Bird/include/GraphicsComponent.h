#pragma once
#include "MediaCache.h"
class GameObject;

class GraphicsComponent {
public:
	virtual ~GraphicsComponent() {}
	virtual void render(GameObject& obj, const double dt, MediaCache& mc) = 0;
};

class BirdGraphicsComponent : public GraphicsComponent {
public:
	virtual void render(GameObject& obj, const double dt, MediaCache& mc) override;
};

class PipeGraphicsComponent : public GraphicsComponent {
public:
	virtual void render(GameObject& obj, const double dt, MediaCache& mc) override;
};