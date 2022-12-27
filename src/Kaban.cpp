#include "Resource.hpp"
#include "Game.hpp"
#include "Kaban.hpp"

Kaban::Kaban(void)
{
	this->image_data = GetImageData(PLAYER3);
	InitializeStatus(Game::PLAYER_TYPE_KABAN);
}

Kaban::~Kaban(void)
{
}
