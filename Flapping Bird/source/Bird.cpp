#include "Bird.h"

Bird::Bird() : GameObject(std::make_unique<BirdInputComponent>(),
							std::make_unique<BirdGraphicsComponent>())
{
	setImage("files/bird.bmp");
}

Bird::~Bird()
{

}

const SDL_Rect& Bird::getBox()
{
	box.x = static_cast<int>(position.x);
	box.y = static_cast<int>(position.y);
	box.w = WIDTH;
	box.h = HEIGHT;

	return box;
}

void Bird::update(const double dt, const int lvlHeight)
{
	direction.y += GRAVITY * dt;

	position.y += direction.y;

	if (position.y <= 0 || position.y + HEIGHT >= lvlHeight)
	{
		alive = false;
	}
}

void Bird::reset()
{
	alive = true;
	setDirection({ 0,0 });
}