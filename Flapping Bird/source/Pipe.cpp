#include "Pipe.h"

Pipe::Pipe(const int scrWidth, const int y, bool pipeFlip) : GameObject(std::make_unique<PipeInputComponent>(),
																	std::make_unique<PipeGraphicsComponent>())
{
	if (pipeFlip)
	{
		setFlip(SDL_FLIP_VERTICAL);
		setPosition({ scrWidth + WIDTH, y });
	}
	else
	{
		setPosition({ scrWidth + WIDTH, y + HEIGHT + GAP });
	}
	
	setDirection({ -1,0 });
	setSpeed(PIPE_SPEED);
	setImage("files/pipe.bmp");
	
}

Pipe::~Pipe()
{

}

const SDL_Rect& Pipe::getBox()
{
	box.x = static_cast<int>(position.x);
	box.y = static_cast<int>(position.y);
	box.w = WIDTH;
	box.h = HEIGHT;

	return box;
}

void Pipe::update(const double dt)
{
	position.x += direction.x * speed * dt;

	if (position.x < -WIDTH)
	{
		onScreen = false;
	}
}