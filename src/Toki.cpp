#include "Resource.hpp"
#include "Game.hpp"
#include "Toki.hpp"

Toki::Toki(void)
{
	this->image_data = GetImageData(PLAYER4);
	InitializeStatus(Game::PLAYER_TYPE_TOKI);
}

Toki::~Toki(void)
{
}
