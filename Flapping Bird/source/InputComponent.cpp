#include "InputComponent.h"
#include "GameObject.h"

void BirdInputComponent::handleEvents(GameObject& obj, SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_SPACE: 
				obj.setDirection({ 0,-5 }); 
				break;
			default: 
				break;
		}
	}
}