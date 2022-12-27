#include "Resource.hpp"
#include "Game.hpp"
#include "Tsuchinoko.hpp"

Tsuchinoko::Tsuchinoko(void)
{
	this->image_data = GetImageData(PLAYER1);
	InitializeStatus(Game::PLAYER_TYPE_TSUCHINOKO);
}

Tsuchinoko::~Tsuchinoko(void)
{
}
