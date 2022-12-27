#include "Resource.hpp"
#include "Game.hpp"
#include "Serval.hpp"

Serval::Serval(void)
{
	this->image_data = GetImageData(PLAYER2);
	InitializeStatus(Game::PLAYER_TYPE_SERVAL);
}

Serval::~Serval(void)
{
}
