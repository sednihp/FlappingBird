#include "GraphicsComponent.h"
#include "GameObject.h"
#include <iostream>

void BirdGraphicsComponent::render(GameObject& obj, const double dt, MediaCache& mc) 
{
	Point2D p = obj.getPosition();
	p.y += obj.getDirection().y * dt;
	mc.render(mc.getImage(obj.getImage()), p);
}

void PipeGraphicsComponent::render(GameObject& obj, const double dt, MediaCache& mc)
{
	Point2D p = obj.getPosition();
	p.y += obj.getDirection().y * dt;
	if (obj.isFlipped())
	{
		mc.render(mc.getImage(obj.getImage()), p, obj.getFlip());
	}
	else
	{
		mc.render(mc.getImage(obj.getImage()), p);
	}
}